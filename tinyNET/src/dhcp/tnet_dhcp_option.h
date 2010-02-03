/*
* Copyright (C) 2009 Mamadou Diop.
*
* Contact: Mamadou Diop <diopmamadou@yahoo.fr>
*	
* This file is part of Open Source Doubango Framework.
*
* DOUBANGO is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*	
* DOUBANGO is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*	
* You should have received a copy of the GNU General Public License
* along with DOUBANGO.
*
*/
/**@file tnet_dhcp_option.h
 * @brief DHCP Options and BOOTP Vendor Extensions as per RFC 2132.
 *
 * @author Mamadou Diop <diopmamadou(at)yahoo.fr>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */

#ifndef TNET_DHCP_OPTION_H
#define TNET_DHCP_OPTION_H

#include "tinyNET_config.h"

#include "tsk_buffer.h"

TNET_BEGIN_DECLS

#define TNET_DHCP_OPTION_CREATE()						tsk_object_new(tnet_dhcp_option_def_t)

#define TNET_DHCP_OPTION(self)							((tnet_dhcp_option_t*)(self))

typedef enum tnet_dhcp_option_tag_e
{
	dhcp_tag_Pad= 0         ,/**< Pad                              0       None                                              [RFC2132] */    
	dhcp_tag_Subnet_Mask= 1         ,/**< Subnet Mask                      4       Subnet Mask Value                                 [RFC2132] */
	dhcp_tag_Time_Offset= 2         ,/**< Time Offset                      4       Time Offset in Seconds from UTC                   [RFC2132] (note: deprecated by 100 and 101) */ 
	dhcp_tag_Router= 3         ,/**< Router                           N       N/4 Router addresses                              [RFC2132] */ 
	dhcp_tag_Time_Server= 4         ,/**< Time Server                      N       N/4 Timeserver addresses                          [RFC2132] */ 
	dhcp_tag_Name_Server= 5         ,/**< Name Server                      N       N/4 IEN-116 Server addresses                      [RFC2132] */
	dhcp_tag_Domain_Server= 6         ,/**< Domain Server                    N       N/4 DNS Server addresses                          [RFC2132]  */
	dhcp_tag_Log_Server= 7         ,/**< Log Server                       N       N/4 Logging Server addresses                      [RFC2132]  */
	dhcp_tag_Quotes_Server= 8         ,/**< Quotes Server                    N       N/4 Quotes Server addresses                       [RFC2132]  */
	dhcp_tag_LPR_Server= 9         ,/**< LPR Server                       N       N/4 Printer Server addresses                      [RFC2132]  */
	dhcp_tag_Impress_Server= 10        ,/**< Impress Server                   N       N/4 Impress Server addresses                      [RFC2132]  */
	dhcp_tag_RLP_Server= 11        ,/**< RLP Server                       N       N/4 RLP Server addresses                          [RFC2132]  */
	dhcp_tag_Hostname= 12        ,/**< Hostname                         N       Hostname string                                   [RFC2132]  */
	dhcp_tag_Boot_File_Size= 13        ,/**< Boot File Size                   2       Size of boot file in 512 byte chunks              [RFC2132]  */
	dhcp_tag_Merit_Dump_File= 14        ,/**< Merit Dump File                  N       Client to dump and name the file to dump it to    [RFC2132]  */
	dhcp_tag_Domain_Name= 15        ,/**< Domain Name                      N       The DNS domain name of the client                 [RFC2132]  */
	dhcp_tag_Swap_Server= 16        ,/**< Swap Server                      N       Swap Server address                               [RFC2132]  */
	dhcp_tag_Root_Path= 17        ,/**< Root Path                        N       Path name for root disk                           [RFC2132]  */
	dhcp_tag_Extension_File= 18        ,/**< Extension File                   N       Path name for more BOOTP info                     [RFC2132]  */
	dhcp_tag_Forward_On_Off= 19        ,/**< Forward On/Off                   1       Enable/Disable IP Forwarding                      [RFC2132]  */
	dhcp_tag_SrcRte_On_Off = 20        ,/**< SrcRte On/Off                    1       Enable/Disable Source Routing                     [RFC2132]  */
	dhcp_tag_Policy_Filter= 21        ,/**< Policy Filter                    N       Routing Policy Filters                            [RFC2132]  */
	dhcp_tag_Max_DG_Assembly= 22        ,/**< Max DG Assembly                  2       Max Datagram Reassembly Size                      [RFC2132]  */
	dhcp_tag_Default_IP_TTL= 23        ,/**< Default IP TTL                   1       Default IP Time to Live                           [RFC2132]  */
	dhcp_tag_MTU_Timeout= 24        ,/**< MTU Timeout                      4       Path MTU Aging Timeout                            [RFC2132]  */
	dhcp_tag_MTU_Plateau= 25        ,/**< MTU Plateau                      N       Path MTU  Plateau Table                           [RFC2132]  */
	dhcp_tag_MTU_Interface= 26        ,/**< MTU Interface                    2       Interface MTU Size                                [RFC2132]  */
	dhcp_tag_MTU_Subnet= 27        ,/**< MTU Subnet                       1       All Subnets are Local                             [RFC2132]  */
	dhcp_tag_Broadcast_Address= 28        ,/**< Broadcast Address                4       Broadcast Address                                 [RFC2132]  */
	dhcp_tag_Mask_Discovery= 29        ,/**< Mask Discovery                   1       Perform Mask Discovery                            [RFC2132]  */
	dhcp_tag_Mask_Supplier= 30        ,/**< Mask Supplier                    1       Provide Mask to Others                            [RFC2132]  */
	dhcp_tag_Router_Discovery= 31        ,/**< Router Discovery                 1       Perform Router Discovery                          [RFC2132]  */
	dhcp_tag_Router_Request= 32        ,/**< Router Request                   4       Router Solicitation Address                       [RFC2132]  */
	dhcp_tag_Static_Route= 33        ,/**< Static Route                     N       Static Routing Table                              [RFC2132]  */
	dhcp_tag_Trailers= 34        ,/**< Trailers                         1       Trailer Encapsulation                             [RFC2132]  */
	dhcp_tag_ARP_Timeout= 35        ,/**< ARP Timeout                      4       ARP Cache Timeout                                 [RFC2132]  */
	dhcp_tag_Ethernet= 36        ,/**< Ethernet                         1       Ethernet Encapsulation                            [RFC2132]  */
	dhcp_tag_Default_TCP_TTL= 37        ,/**< Default TCP TTL                  1       Default TCP Time to Live                          [RFC2132]  */
	dhcp_tag_Keepalive_Time= 38        ,/**< Keepalive Time                   4       TCP Keepalive Interval                            [RFC2132]  */
	dhcp_tag_Keepalive_Data= 39        ,/**< Keepalive Data                   1       TCP Keepalive Garbage                             [RFC2132]  */
	dhcp_tag_NIS_Domain= 40        ,/**< NIS Domain                       N       NIS Domain Name                                   [RFC2132]  */
	dhcp_tag_NIS_Servers= 41        ,/**< NIS Servers                      N       NIS Server Addresses                              [RFC2132]  */
	dhcp_tag_NTP_Servers= 42        ,/**< NTP Servers                      N       NTP Server Addresses                              [RFC2132]  */
	dhcp_tag_Vendor_Specific= 43        ,/**< Vendor Specific                  N       Vendor Specific Information                       [RFC2132]  */
	dhcp_tag_NETBIOS_Name_Srv= 44        ,/**< NETBIOS Name Srv                 N       NETBIOS Name Servers                              [RFC2132]  */
	dhcp_tag_NETBIOS_Dist_Srv= 45        ,/**< NETBIOS Dist Srv                 N       NETBIOS Datagram Distribution                     [RFC2132]  */
	dhcp_tag_NETBIOS_Node_Type= 46        ,/**< NETBIOS Node Type                1       NETBIOS Node Type                                 [RFC2132]  */
	dhcp_tag_NETBIOS_Scope= 47        ,/**< NETBIOS Scope                    N       NETBIOS Scope                                     [RFC2132]  */
	dhcp_tag_X_Window_Font= 48        ,/**< X Window Font                    N       X Window Font Server                              [RFC2132]  */
	dhcp_tag_X_Window_Manager= 49        ,/**< X Window Manager                 N       X Window Display Manager                          [RFC2132]  */
	dhcp_tag_Address_Request= 50        ,/**< Address Request                  4       Requested IP Address                              [RFC2132]  */
	dhcp_tag_Address_Time= 51        ,/**< Address Time                     4       IP Address Lease Time                             [RFC2132]  */
	dhcp_tag_Overload= 52        ,/**< Overload                         1       Overload "sname" or "file"                        [RFC2132]  */
	dhcp_tag_DHCP_Msg_Type= 53        ,/**< DHCP Msg Type                    1       DHCP Message Type                                 [RFC2132]  */
	dhcp_tag_DHCP_Server_Id= 54        ,/**< DHCP Server Id                   4       DHCP Server Identification                        [RFC2132]  */
	dhcp_tag_Parameter_List= 55        ,/**< Parameter List                   N       Parameter Request List                            [RFC2132]  */
	dhcp_tag_DHCP_Message= 56        ,/**< DHCP Message                     N       DHCP Error Message                                [RFC2132]  */
	dhcp_tag_DHCP_Max_Msg_Size= 57        ,/**< DHCP Max Msg Size                2       DHCP Maximum Message Size                         [RFC2132]  */
	dhcp_tag_Renewal_Time= 58        ,/**< Renewal Time                     4       DHCP Renewal (T1) Time                            [RFC2132]  */
	dhcp_tag_Rebinding_Time= 59        ,/**< Rebinding Time                   4       DHCP Rebinding (T2) Time                          [RFC2132]  */
	dhcp_tag_Class_Id= 60        ,/**< Class Id                         N       Class Identifier                                  [RFC2132]  */
	dhcp_tag_Client_Id= 61        ,/**< Client Id                        N       Client Identifier                                 [RFC2132]  */
	dhcp_tag_NetWare_IP_Domain= 62        ,/**< NetWare/IP Domain                N       NetWare/IP Domain Name                            [RFC2242]  */
	dhcp_tag_NetWare_IP_Option= 63        ,/**< NetWare/IP Option                N       NetWare/IP sub Options                            [RFC2242]  */
	dhcp_tag_NIS_Domain_Name= 64        ,/**< NIS-Domain-Name                  N       NIS+ v3 Client Domain Name                        [RFC2132]  */
	dhcp_tag_NIS_Server_Addr = 65        ,/**< NIS-Server-Addr                  N       NIS+ v3 Server Addresses                          [RFC2132]  */
	dhcp_tag_Server_Name= 66        ,/**< Server-Name                      N       TFTP Server Name                                  [RFC2132]  */
	dhcp_tag_Bootfile_Name= 67        ,/**< Bootfile-Name                    N       Boot File Name                                    [RFC2132]  */
	dhcp_tag_Home_Agent_Addrs= 68        ,/**< Home-Agent-Addrs                 N       Home Agent Addresses                              [RFC2132]  */
	dhcp_tag_SMTP_Server= 69        ,/**< SMTP-Server                      N       Simple Mail Server Addresses                      [RFC2132]  */
	dhcp_tag_POP3_Server= 70        ,/**< POP3-Server                      N       Post Office Server Addresses                      [RFC2132]  */
	dhcp_tag_NNTP_Server= 71        ,/**< NNTP-Server                      N       Network News Server Addresses                     [RFC2132]  */
	dhcp_tag_WWW_Server= 72        ,/**< WWW-Server                       N       WWW Server Addresses                              [RFC2132]  */
	dhcp_tag_Finger_Server= 73        ,/**< Finger-Server                    N       Finger Server Addresses                           [RFC2132]  */
	dhcp_tag_IRC_Server= 74        ,/**< IRC-Server                       N       Chat Server Addresses                             [RFC2132]  */
	dhcp_tag_StreetTalk_Server= 75        ,/**< StreetTalk-Server                N       StreetTalk Server Addresses                       [RFC2132]  */
	dhcp_tag_STDA_Server= 76        ,/**< STDA-Server                      N       ST Directory Assist. Addresses                    [RFC2132]  */
	dhcp_tag_User_Class= 77        ,/**< User-Class                       N       User Class Information                            [RFC3004]  */
	dhcp_tag_Directory_Agent = 78        ,/**< Directory Agent                  N       directory agent information                       [RFC2610]  */
	dhcp_tag_Service_Scope = 79        ,/**< Service Scope                    N       service location agent scope                      [RFC2610]  */
	dhcp_tag_Rapid_Commit= 80        ,/**< Rapid Commit                     0       Rapid Commit                                      [RFC4039]  */
	dhcp_tag_Client_FQDN = 81        ,/**< Client FQDN                      N       Fully Qualified Domain Name                       [RFC4702]  */
	dhcp_tag_Relay_Agent_Information= 82        ,/**< Relay Agent Information          N       Relay Agent Information                           [RFC3046]  */
	dhcp_tag_iSNS= 83        ,/**< iSNS                             N       Internet Storage Name Service                     [RFC4174] */
	//84    REMOVED/Unassigned                                                                         [RFC3679] */
	dhcp_tag_NDS_Servers= 85        ,/**< NDS Servers                      N       Novell Directory Services                         [RFC2241]  */
	dhcp_tag_NDS_Tree_Name= 86        ,/**< NDS Tree Name                    N       Novell Directory Services                         [RFC2241]  */
	dhcp_tag_NDS_Context= 87        ,/**< NDS Context                      N       Novell Directory Services                         [RFC2241]  */
	dhcp_tag_BCMCS_Controller_Domain_Name_list= 88        ,/**< BCMCS Controller Domain Name list                                                          [RFC4280] */
	dhcp_tag_BCMCS_Controller_IPv4_address_option= 89        ,/**< BCMCS Controller IPv4 address option                                                       [RFC4280] */
	dhcp_tag_Authentication= 90        ,/**< Authentication                   N       Authentication                                    [RFC3118]  */
	dhcp_tag_client_last_transaction_time= 91        ,/**< client-last-transaction-time option                                                        [RFC4388]   */
	dhcp_tag_associated_ip= 92        ,/**< associated-ip option                                                                       [RFC4388]  */
	dhcp_tag_Client_System = 93        ,/**< Client System                    N       Client System Architecture                        [RFC4578]  */
	dhcp_tag_Client_NDI = 94        ,/**< Client NDI                       N       Client Network Device Interface                   [RFC4578] */
	dhcp_tag_LDAP= 95        ,/**< LDAP                             N       Lightweight Directory Access Protocol             [RFC3679]  */
	dhcp_tag_REMOVED_Unassigned= 96        ,/**< REMOVED/Unassigned                                                                         [RFC3679]  */
	dhcp_tag_UUID_GUID= 97        ,/**< UUID/GUID                        N       UUID/GUID-based Client Identifier                 [RFC4578] */
	dhcp_tag_User_Auth= 98        ,/**< User-Auth                        N       Open Group's User Authentication                  [RFC2485]  */
	dhcp_tag_GEOCONF_CIVIC= 99        ,/**< GEOCONF_CIVIC                                                                              [RFC4776] */
	dhcp_tag_PCode= 100       ,/**< PCode                            N       IEEE 1003.1 TZ String                             [RFC4833] */
	dhcp_tag_TCode= 101       ,/**< TCode                            N       Reference to the TZ Database                      [RFC4833]  */
	//102-107   REMOVED/Unassigned                                                                         [RFC3679]
	//108       REMOVED/Unassigned                                                                         [RFC3679]
	//109       Unassigned                                                                                 [RFC3679]
	//110       REMOVED/Unassigned                                                                         [RFC3679]
	//111       Unassigned                                                                                 [RFC3679]
	dhcp_tag_Netinfo_Address= 112       ,/**< Netinfo Address                  N       NetInfo Parent Server Address                     [RFC3679]  */
	dhcp_tag_Netinfo_Tag= 113       ,/**< Netinfo Tag                      N       NetInfo Parent Server Tag                         [RFC3679]  */
	dhcp_tag_= 114       ,/**< URL                              N       URL                                               [RFC3679] */
	//115       REMOVED/Unassigned                                                                         [RFC3679] 
	dhcp_tag_Auto_Config= 116       ,/**< Auto-Config                      N       DHCP Auto-Configuration                           [RFC2563]  */
	dhcp_tag_Name_Service_Search= 117       ,/**< Name Service Search              N       Name Service Search                               [RFC2937]  */
	dhcp_tag_Subnet_Selection_Option= 118       ,/**< Subnet Selection Option          4       Subnet Selection Option                           [RFC3011]  */
	dhcp_tag_Domain_Search= 119       ,/**< Domain Search                    N       DNS domain search list                            [RFC3397]  */
	dhcp_tag_SIP_Servers_DHCP_Option= 120       ,/**< SIP Servers DHCP Option          N       SIP Servers DHCP Option                           [RFC3361]  */
	dhcp_tag_Classless_Static_Route_Option= 121       ,/**< Classless Static Route Option    N       Classless Static Route Option                     [RFC3442]  */
	dhcp_tag_CCC= 122       ,/**< CCC                              N       CableLabs Client Configuration                    [RFC3495] */
	dhcp_tag_GeoConf_Option= 123       ,/**< GeoConf Option                   16      GeoConf Option                                    [RFC3825] */
	dhcp_tag_V_I_Vendor_Class= 124       ,/**< V-I Vendor Class                         Vendor-Identifying Vendor Class                   [RFC3925] */
	dhcp_tag_V_I_Vendor_Specific_Information= 125       ,/**< V-I Vendor-Specific Information          Vendor-Identifying Vendor-Specific Information    [RFC3925] */
	//dhcp_tag_= 126       ,/**< Removed/Unassigned                                                                         [RFC3679] */
	//dhcp_tag_= 127       ,/**< Removed/Unassigned                                                                         [RFC3679] */
	//dhcp_tag_PXE - undefined= 128       ,/**< PXE - undefined (vendor specific)                                                          [RFC4578] */
	dhcp_tag_Etherboot_signature= 128       ,/**< Etherboot signature. 6 bytes: E4:45:74:68:00:00	 */
	dhcp_tag_DOCSIS= 128       ,/**< DOCSIS "full security" server IP address	 */
	dhcp_tag_TFTP_Server_IP= 128       ,/**< TFTP Server IP address (for IP Phone software load)	 */
	//dhcp_tag_= 129       ,/**< PXE - undefined (vendor specific)                                                          [RFC4578] */
	dhcp_tag_Kernel_options= 129       ,/**< Kernel options. Variable length string	 */
	dhcp_tag_Call_Server_IP= 129       ,/**< Call Server IP address 	 */
	//dhcp_tag_= 130       ,/**< PXE - undefined (vendor specific)                                                          [RFC4578] */
	dhcp_tag_Ethernet_interface= 130       ,/**< Ethernet interface. Variable length string.	 */
	dhcp_tag_Discrimination= 130       ,/**< Discrimination string (to identify vendor)	 */
	//dhcp_tag_= 131       ,/**< PXE - undefined (vendor specific)                                                          [RFC4578] */
	dhcp_tag_Remote_statistics_server_IP= 131       ,/**< Remote statistics server IP address 	 */
	//dhcp_tag_= 132       ,/**< PXE - undefined (vendor specific)                                                          [RFC4578] */
	dhcp_tag_IEEE_802_1Q_VLAN_ID= 132       ,/**< IEEE 802.1Q VLAN ID 	 */
	//dhcp_tag_= 133       ,/**< PXE - undefined (vendor specific)                                                          [RFC4578] */
	dhcp_tag_IEEE_802_1D_p= 133       ,/**< IEEE 802.1D/p Layer 2 Priority	 */
	//dhcp_tag_= 134       ,/**< PXE - undefined (vendor specific)                                                          [RFC4578] */
	dhcp_tag_DSCP= 134       ,/**< Diffserv Code Point (DSCP) for VoIP signalling and media streams	 */
	//dhcp_tag_= 135       ,/**< PXE - undefined (vendor specific)                                                          [RFC4578] */
	dhcp_tag_HTTP_Proxy= 135       ,/**< HTTP Proxy for phone-specific applications	 */
	dhcp_tag_OPTION_PANA_AGENT= 136       ,/**< OPTION_PANA_AGENT                                                                          [RFC5192] */
	dhcp_tag_OPTION_V4_LOST= 137       ,/**< OPTION_V4_LOST                                                                             [RFC5223] */
	dhcp_tag_OPTION_CAPWAP_AC_V4= 138       ,/**< OPTION_CAPWAP_AC_V4              N       CAPWAP Access Controller addresses                [RFC5417] */
	dhcp_tag_OPTION_IPv4_Address_MoS= 139       ,/**< OPTION-IPv4_Address-MoS          N       a series of suboptions                            [RFC5678] */
	dhcp_tag_OPTION_IPv4_FQDN_MoS= 140       ,/**< OPTION-IPv4_FQDN-MoS             N       a series of suboptions                            [RFC5678] */
	//141-149   Unassigned                                                                                 [RFC3942] */
	dhcp_tag_TFTP_server_address= 150       ,/**< TFTP server address (Tentatively Assigned - 2005-06-23) */
	dhcp_tag_Etherboot= 150       ,/**< Etherboot	 */
	dhcp_tag_GRUB_configuration_path_name= 150       ,/**< GRUB configuration path name	 */
	//151-174   Unassigned                                                                                 [RFC3942]
	//dhcp_tag_Etherboot= 175       ,/**< Etherboot (Tentatively Assigned - 2005-06-23) */
	dhcp_tag_IP_Telephone= 176       ,/**< IP Telephone (Tentatively Assigned - 2005-06-23) */
	//dhcp_tag_Etherboot= 177       ,/**< Etherboot (Tentatively Assigned - 2005-06-23) */
	dhcp_tag_PacketCable_and_CableHome= 177       ,/**< PacketCable and CableHome (replaced by 122)	 */
	//178-207   Unassigned                                                                                 [RFC3942]
	dhcp_tag_PXELINUX_Magic= 208       ,/**< PXELINUX Magic                   4       magic string = F1:00:74:7E                        [RFC5071] Deprecated */
	dhcp_tag_Configuration_File= 209       ,/**< Configuration File               N       Configuration file                                [RFC5071] */
	dhcp_tag_Path_Prefix= 210       ,/**< Path Prefix                      N       Path Prefix Option                                [RFC5071] */
	dhcp_tag_Reboot_Time = 211       ,/**< Reboot Time                      4       Reboot Time                                       [RFC5071] */
	// 212-219   Unassigned
	dhcp_tag_Subnet_Allocation= 220       ,/**< Subnet Allocation Option (Tentatively Assigned - 2005-06-23) */
	dhcp_tag_Virtual_Subnet= 221       ,/**< Virtual Subnet Selection Option (Tentatively Assigned - 2005-06-23) */
	// 222-223   Unassigned                                                                                 [RFC3942]
	//224-254   Reserved (Private Use)
	dhcp_tag_reserved=224 ,
	dhcp_tag_End= 255       ,/**< End                              0         None                                            [RFC2132]  */
}
tnet_dhcp_option_tag_t;

/** DHCP/BOOTP option as per RFC 2132.
*	Format ==> subclause 2.
*/
typedef struct tnet_dhcp_option_s
{
	TSK_DECLARE_OBJECT;
	
	unsigned initialized:1;

	tnet_dhcp_option_tag_t tag; /**< 1-byte option-tag. */
	uint8_t length;
	tsk_buffer_t *data;
}
tnet_dhcp_option_t;

typedef tsk_list_t tnet_dhcp_options_L_t;

#define TNET_DECLARE_HCP_OPTION tnet_dhcp_option_t dhcp_option

int tnet_dhcp_option_init(tnet_dhcp_option_t *option, tnet_dhcp_option_tag_t tag);
int tnet_dhcp_option_deinit(tnet_dhcp_option_t *option);

tnet_dhcp_option_t* tnet_dhcp_option_deserialize(const void* data, size_t size);
int tnet_dhcp_option_serialize(const tnet_dhcp_option_t* option, tsk_buffer_t *output);

TINYNET_GEXTERN const void *tnet_dhcp_option_def_t;

TNET_END_DECLS

#endif /* TNET_DHCP_OPTION_H */
