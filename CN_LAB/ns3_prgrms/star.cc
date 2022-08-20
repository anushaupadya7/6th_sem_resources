// Star topology using point to point protocol

#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/applications-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/point-to-point-layout-module.h"
#include "ns3/netanim-module.h"

using namespace ns3;

int main ()
{
 std::string animFile="fourth.xml";

 PointToPointHelper ptp;
 ptp.SetDeviceAttribute ("DataRate", StringValue ("5Mbps"));
 ptp.SetChannelAttribute ("Delay", StringValue ("2ms"));
 
 PointToPointStarHelper star (8, ptp); //8 nodes
 
 InternetStackHelper internet;
 star.InstallStack (internet);
 star.AssignIpv4Addresses (Ipv4AddressHelper ("10.1.1.0", "255.255.255.0"));
 Address hubLocalAddress (InetSocketAddress (Ipv4Address::GetAny (), 50000));
 
 PacketSinkHelper sink ("ns3::TcpSocketFactory", hubLocalAddress);
 ApplicationContainer hubApp = sink.Install (star.GetHub ());
 hubApp.Start (Seconds (1.0));
 hubApp.Stop (Seconds (10.0));
 
 OnOffHelper onOffHelper ("ns3::TcpSocketFactory", Address ());
 onOffHelper.SetAttribute ("OnTime", StringValue ("ns3::ConstantRandomVariable[Constant=1]"));
 onOffHelper.SetAttribute ("OffTime", StringValue ("ns3::ConstantRandomVariable[Constant=0]"));
 
 ApplicationContainer spokeApps;
 for (uint32_t i = 0; i < star.SpokeCount (); ++i)
 {
	 AddressValue remoteAddress (InetSocketAddress (star.GetHubIpv4Address (i), 50000)); // 50000 is the port number
	 onOffHelper.SetAttribute ("Remote", remoteAddress);
	 spokeApps.Add (onOffHelper.Install (star.GetSpokeNode (i)));
 }
 spokeApps.Start (Seconds (1.0));
 spokeApps.Stop (Seconds (10.0));
 
 Ipv4GlobalRoutingHelper::PopulateRoutingTables ();
 
 ptp.EnablePcapAll ("star");
 
 AnimationInterface anim(animFile);
 anim.SetConstantPosition(star.GetHub(),10.0,60.0);

 Simulator::Run ();
 Simulator::Destroy ();
 return 0;
}