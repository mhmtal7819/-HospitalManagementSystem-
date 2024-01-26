#include "Patient.h"
#include <iostream>
#include <string>



Patient::Patient(string name, string surname,int id) {
	setId(id);
	setName(name);
	setSurname(surname);
}
Patient::Patient() {

}
void Patient::setName(string name) {
	this->name = name;
}
void Patient::setSurname(string surname) {
	this->surname = surname;
}
void Patient::setHeight(int height) {
	this->height = height;
}
void Patient::setWeight(int weight) {
	this->weight = weight;
}
void Patient::setId(int id=0) {
	this->id = id;
}

string Patient::getName() {
	return name;
}
string Patient::getSurname() {
	return surname;
}
int Patient::getHeight() {
	return height;
}
int Patient::getWeight() {
	return weight;
}
int Patient::getIId() {
	id++;
	setId(id);
	return id;
}
int Patient::getId() {
	return id;
}