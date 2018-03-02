CC=g++
CFLAGS=-Wall -std=c++11 -O3 -pthread
INCLUDE = -I .
LINK = -L .
Files = main.cpp attack_method.cpp boss.cpp character.cpp creature.cpp item.cpp loot.cpp merchant.cpp monster.cpp player.cpp quest.cpp quest_giver.cpp spell.cpp

all:
	${CC} ${Files} -o RPG ${CFLAGS} ${INCLUDE} ${LINK}