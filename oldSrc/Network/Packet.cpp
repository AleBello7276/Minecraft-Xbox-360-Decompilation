#include "Packet.h"




void Packet::staticCtor()
{
    
	addIdClassMapping(0, true, true, typeid(Packet0KeepAlive));
	addIdClassMapping(1, true, true, typeid(Packet1Login));
	addIdClassMapping(2, true, true, typeid(Packet2Handshake));
	addIdClassMapping(3, true, true, typeid(Packet3Chat));
	addIdClassMapping(4, true, false, typeid(Packet4UpdateTime));
	addIdClassMapping(5, true, false, typeid(Packet5PlayerInventory));
	addIdClassMapping(6, true, false, typeid(Packet6SpawnPosition));
	addIdClassMapping(7, false, true, typeid(Packet7UseEntity));
	addIdClassMapping(8, true, false, typeid(Packet8UpdateHealth));
	addIdClassMapping(9, true, true, typeid(Packet9Respawn));
	addIdClassMapping(10, true, true, typeid(Packet10Flying));
	addIdClassMapping(11, true, true, typeid(Packet11PlayerPosition));
	addIdClassMapping(12, true, true, typeid(Packet12PlayerLook));
	addIdClassMapping(13, true, true, typeid(Packet13PlayerLookMove));
	addIdClassMapping(14, false, true, typeid(Packet14BlockDig));
	addIdClassMapping(15, false, true, typeid(Packet15Place));
	addIdClassMapping(16, false, true, typeid(Packet16BlockItemSwitch));
	addIdClassMapping(17, true, false, typeid(Packet17Sleep));
	addIdClassMapping(18, true, true, typeid(Packet18Animation));
	addIdClassMapping(19, false, true, typeid(Packet19EntityAction));
	addIdClassMapping(20, true, false, typeid(Packet20NamedEntitySpawn));
	addIdClassMapping(21, true, false, typeid(Packet21PickupSpawn));
	addIdClassMapping(22, true, false, typeid(Packet22Collect)); 
	addIdClassMapping(23, true, false, typeid(Packet23VehicleSpawn));
	addIdClassMapping(24, true, false, typeid(Packet24MobSpawn));
	addIdClassMapping(25, true, false, typeid(Packet25EntityPainting));
	addIdClassMapping(27, false, true, typeid(Packet27Position));
	addIdClassMapping(28, true, false, typeid(Packet28EntityVelocity));
	addIdClassMapping(29, true, false, typeid(Packet29DestroyEntity));
	addIdClassMapping(30, true, false, typeid(Packet30Entity));
	addIdClassMapping(31, true, false, typeid(Packet31RelEntityMove));
	addIdClassMapping(32, true, false, typeid(Packet32EntityLook));
	addIdClassMapping(33, true, false, typeid(Packet33RelEntityMoveLook));
	addIdClassMapping(34, true, false, typeid(Packet34EntityTeleport));
	addIdClassMapping(38, true, false, typeid(Packet38EntityStatus));
	addIdClassMapping(39, true, false, typeid(Packet39AttachEntity));
	addIdClassMapping(40, true, false, typeid(Packet40EntityMetadata));
	addIdClassMapping(50, true, false, typeid(Packet50PreChunk));
	addIdClassMapping(51, true, false, typeid(Packet51MapChunk));
	addIdClassMapping(52, true, false, typeid(Packet52MultiBlockChange));
	addIdClassMapping(53, true, false, typeid(Packet53BlockChange));
	addIdClassMapping(54, true, false, typeid(Packet54PlayNoteBlock));
	addIdClassMapping(60, true, false, typeid(Packet60Explosion));
	addIdClassMapping(61, true, false, typeid(Packet61DoorChange));
	addIdClassMapping(70, true, false, typeid(Packet70Bed));
	addIdClassMapping(71, true, false, typeid(Packet71Weather));
	addIdClassMapping(100, true, false, typeid(Packet100OpenWindow));
	addIdClassMapping(101, true, true, typeid(Packet101CloseWindow));
	addIdClassMapping(102, false, true, typeid(Packet102WindowClick));
	addIdClassMapping(103, true, false, typeid(Packet103SetSlot));
	addIdClassMapping(104, true, false, typeid(Packet104WindowItems));
	addIdClassMapping(105, true, false, typeid(Packet105UpdateProgressbar));
	addIdClassMapping(106, true, true, typeid(Packet106Transaction));
	addIdClassMapping(130, true, true, typeid(Packet130UpdateSign));
	addIdClassMapping(131, true, false, typeid(Packet131MapData));
	addIdClassMapping(200, true, false, typeid(Packet200Statistic));
	addIdClassMapping(255, true, true, typeid(Packet255KickDisconnect));
	//packetStats = new HashMap();
	//totalPacketsCount = 0;
	
}

// Define the static variables
//std::unordered_map<int, std::type_index> Packet::packetIdToClassMap;
//std::unordered_map<std::type_index, int> Packet::packetClassToIdMap;
std::vector<int> Packet::clientPacketIdList;
std::vector<int> Packet::serverPacketIdList;




void Packet::addIdClassMapping(int id, bool isClient, bool isServer, const std::type_index& type) 
{
    


    //if (packetIdToClassMap.find(id) != packetIdToClassMap.end()) {
    //    //throw std::invalid_argument("Duplicate packet id: " + std::to_string(id));
    //}
    //if (packetClassToIdMap.find(type) != packetClassToIdMap.end()) {
    //    //throw std::invalid_argument("Duplicate packet class.");
    //}
    //packetIdToClassMap[id] = type;
    //packetClassToIdMap[type] = id;
    if (isClient) {
        clientPacketIdList.push_back(id);
    }
    if (isServer) {
        serverPacketIdList.push_back(id);
    }
}

