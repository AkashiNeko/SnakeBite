#pragma once

#include "game.h"
#include "body.h"
#include <list>
#include <unordered_set>

class Snake {
    Direction dir;
    std::list<Body> snake;
    std::unordered_set<coor_hash_t> uset;
public:
    Snake(Body head, Direction d = Right, size_t size = 3);
    ~Snake();
    class iterator {
	public:
		friend class Snake;
		iterator(std::list<Body>::iterator ptr) :_ptr(ptr) {}
		void operator++() { ++_ptr; }
		bool operator!=(const iterator &it) { return _ptr != it._ptr; }
		Body& operator*() { return *_ptr; }
		Body* operator->() { return &*_ptr; }
	private:
		std::list<Body>::iterator _ptr;
	};
    inline size_t size() {
        return snake.size();
    }
private:
    inline coor_hash_t coorHash(Body body) {
        return static_cast<coor_hash_t>(body.x) << 16 | static_cast<coor_hash_t>(body.y);
    }
};