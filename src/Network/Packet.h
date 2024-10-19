#pragma once


#include <iostream>
#include <unordered_map>
#include <typeindex> 
#include <vector>



class Packet0KeepAlive;
class Packet1Login;
class Packet2Handshake;
class Packet3Chat;
class Packet4UpdateTime;
class Packet5PlayerInventory;
class Packet6SpawnPosition;
class Packet7UseEntity;
class Packet8UpdateHealth;
class Packet9Respawn;
class Packet10Flying;
class Packet11PlayerPosition;
class Packet12PlayerLook;
class Packet13PlayerLookMove;
class Packet14BlockDig;
class Packet15Place;
class Packet16BlockItemSwitch;
class Packet17Sleep;
class Packet18Animation;
class Packet19EntityAction;
class Packet20NamedEntitySpawn;
class Packet21PickupSpawn;
class Packet22Collect;
class Packet23VehicleSpawn;
class Packet24MobSpawn;
class Packet25EntityPainting;
class Packet27Position;
class Packet28EntityVelocity;
class Packet29DestroyEntity;
class Packet30Entity;
class Packet31RelEntityMove;
class Packet32EntityLook;
class Packet33RelEntityMoveLook;
class Packet34EntityTeleport;
class Packet38EntityStatus;
class Packet39AttachEntity;
class Packet40EntityMetadata;
class Packet50PreChunk;
class Packet51MapChunk;
class Packet52MultiBlockChange;
class Packet53BlockChange;
class Packet54PlayNoteBlock;
class Packet60Explosion;
class Packet61DoorChange;
class Packet70Bed;
class Packet71Weather;
class Packet100OpenWindow;
class Packet101CloseWindow;
class Packet102WindowClick;
class Packet103SetSlot;
class Packet104WindowItems;
class Packet105UpdateProgressbar;
class Packet106Transaction;
class Packet130UpdateSign;
class Packet131MapData;
class Packet200Statistic;
class Packet255KickDisconnect;

class Packet
{
public:
    static std::unordered_map<int, std::type_index> packetIdToClassMap;
    static std::unordered_map<std::type_index, int> packetClassToIdMap;
    static std::vector<int> clientPacketIdList;
    static std::vector<int> serverPacketIdList;

    static void staticCtor();
    static void Packet::addIdClassMapping(int id, bool isClient, bool isServer, const std::type_index& type);

private:


};