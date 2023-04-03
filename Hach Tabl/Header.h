#pragma once
#include <iostream>
#include <string>

using namespace std;

const int TABLE_SIZE = 100;

class Node {
public:
    string key;
    int value;
    Node* next;

    Node(string key, int value) {
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }
};

class HashTable {
private:
    Node* table[TABLE_SIZE];

    int hash(string key) {
        int sum = 0;
        for (char c : key) {
            sum += (int)c;
        }
        return sum % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    void insert(string key, int value) {
        int index = hash(key);
        Node* node = new Node(key, value);

        if (table[index] == nullptr) {
            table[index] = node;
        }
        else {
            Node* current = table[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = node;
        }
    }

    int get(string key) {
        int index = hash(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    void remove(string key) {
        int index = hash(key);
        Node* current = table[index];
        Node* previous = nullptr;

        while (current != nullptr) {
            if (current->key == key) {
                if (previous == nullptr) {
                    table[index] = current->next;
                }
                else {
                    previous->next = current->next;
                }
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        }
    }
};