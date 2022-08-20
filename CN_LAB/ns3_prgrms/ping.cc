// Pinging over network topology consisting of 3 nodes

#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/applications-module.h"
#include "ns3/csma-module.h"
#include "ns3/internet-apps-module.h"
#include "ns3/netanim-module.h"

using namespace ns3;

int main (){
 std::string animFile="fifth.xml";

  NodeContainer nodes;
  nodes.Create (3);
 
  CsmaHelper csma;
  //csma.SetChannelAttribute ("DataRate", DataRateValue (DataRate (5000000)));
  //csma.SetChannelAttribute ("Delay", TimeValue (MilliSeconds (2)));
  csma.SetChannelAttribute ("DataRate", StringValue ("5Mbps"));
  csma.SetChannelAttribute ("Delay", StringValue ("2ms"));
  
  NetDeviceContainer devices;
  devices = csma.Install (nodes);

  InternetStackHelper stack;
  stack.Install (nodes);

  Ipv4AddressHelper address;
  address.SetBase ("10.0.1.0", "255.255.255.0");
  Ipv4InterfaceContainer interface = address.Assign (devices);

  V4PingHelper ping = V4PingHelper (interface.GetAddress (2));
  
  NodeContainer pingers;
  pingers.Add (nodes.Get (0));
  pingers.Add (nodes.Get (1));
  
  ApplicationContainer apps = ping.Install (pingers);
  apps.Start (Seconds (2.0));
  apps.Stop (Seconds (5.0));


  csma.EnablePcapAll ("csma-ping", true);
  
  AnimationInterface anim(animFile);
  anim.SetConstantPosition(nodes.Get(0),10.0,60.0);
  anim.SetConstantPosition(nodes.Get(1),10.0,100.0);
  anim.SetConstantPosition(nodes.Get(2),50.0,60.0);
  
 
  Simulator::Run ();
  Simulator::Destroy ();
}