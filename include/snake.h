#pragma once

#include "game.h"
#include "body.h"
#include <List>
#include <unordered_set>

class Snake {
    Direction dir;
    std::list<Body> snake;
    std::unordered_set<Body> set;
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
};