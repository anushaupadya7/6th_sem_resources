// Client - Server using CSMA protocol

#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/applications-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/csma-module.h"
#include "ns3/netanim-module.h"
#include "ns3/ipv4-global-routing-helper.h"

using namespace ns3;

int main (){

  LogComponentEnable ("UdpEchoClientApplication", LOG_LEVEL_INFO);
  LogComponentEnable ("UdpEchoServerApplication", LOG_LEVEL_INFO);
  
  std::string animFile="third.xml";
  
  NodeContainer csmaNodes;
  csmaNodes.Create (4);
  
  CsmaHelper csma;
  csma.SetChannelAttribute ("DataRate", StringValue ("100Mbps"));
  csma.SetChannelAttribute ("Delay", StringValue ("2ms"));

  NetDeviceContainer csmaDevices;
  csmaDevices = csma.Install (csmaNodes);

  InternetStackHelper stack;
  stack.Install (csmaNodes);

  Ipv4AddressHelper address;
  address.SetBase ("10.1.1.0", "255.255.255.0");
  
  Ipv4InterfaceContainer csmaInterfaces = address.Assign (csmaDevices);

  UdpEchoServerHelper echoServer (9);

  ApplicationContainer serverApps = echoServer.Install (csmaNodes.Get (0));
  serverApps.Start (Seconds (1.0));
  serverApps.Stop (Seconds (10.0));

  UdpEchoClientHelper echoClient (csmaInterfaces.GetAddress (0), 9);
  echoClient.SetAttribute ("MaxPackets", UintegerValue (1));
  echoClient.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
  echoClient.SetAttribute ("PacketSize", UintegerValue (1024));

  ApplicationContainer clientApps = echoClient.Install (csmaNodes.Get (3));
  clientApps.Start (Seconds (2.0));
  clientApps.Stop (Seconds (10.0));
  
  Ipv4GlobalRoutingHelper::PopulateRoutingTables();
  
  AnimationInterface anim(animFile);
  anim.SetConstantPosition(csmaNodes.Get(0),45.0,40.0);
  anim.SetConstantPosition(csmaNodes.Get(1),55.0,40.0);
  anim.SetConstantPosition(csmaNodes.Get(2),65.0,40.0);
  anim.SetConstantPosition(csmaNodes.Get(3),75.0,40.0);
  
  AsciiTraceHelper ascii;
  csma.EnableAsciiAll(ascii.CreateFileStream("third.tr"));

  Simulator::Run ();
  Simulator::Destroy ();
  return 0;
}