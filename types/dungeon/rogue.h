#pragma once

#include "dungeon.h"

#include <stdexcept>
#include <deque>
#include <set>
#include <map>

Room* FindFinalRoom(Room* starting_room) {
    std::deque<Room*> deque;
    deque.push_back(starting_room);
    std::set<std::string> keys;
    std::map<Room*, size_t> prev_num_keys;
    while (!deque.empty()) {
        Room* cur_room = deque.front();
        deque.pop_front();
        if (cur_room->IsFinal()) {
            return cur_room;
        }
        for (size_t i = 0; i < cur_room->NumKeys(); ++i) {
            keys.insert(cur_room->GetKey(i));
        }
        if (prev_num_keys.contains(cur_room) && prev_num_keys[cur_room] == keys.size()) {
            continue;
        }
        prev_num_keys[cur_room] = keys.size();
        for (size_t i = 0; i < cur_room->NumDoors(); ++i) {
            Door* cur_door = cur_room->GetDoor(i);
            if (cur_door->IsOpen()) {
                deque.push_back(cur_door->GoThrough());
            } else {
                for (std::string key : keys) {
                    if (cur_door->TryOpen(key)) {
                        deque.push_back(cur_door->GoThrough());
                    }
                }
            }
        }
    }
    return nullptr;
}
