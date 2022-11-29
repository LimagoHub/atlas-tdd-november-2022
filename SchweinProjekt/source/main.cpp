#include <iostream>
#include "calculator_impl.h"
#include "clac_client.h"

int main() {
	calculator_impl impl;
	calc_client client{impl};
	client.go();
	
}