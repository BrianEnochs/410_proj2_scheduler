/*
 * Dispatcher.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

//TODO fill in content

#include "../includes/dispatcher.h"

using namespace std;

PCB Dispatcher::get_from_CPU() {
	return cpu->get_process_off_core();
}

void Dispatcher::put_on_CPU(PCB &process) {
	cpu->put_process_on_core(process);
}

bool Dispatcher::isValidJobOnCPU() {
	return !((cpu->get_COPY_of_Current_Process()).isEmpty());
}
