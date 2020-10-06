/*
 * scheduler.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

//TODO fill in content
#include "../includes/scheduler.h"

using namespace std;

void Scheduler::add(PCB p) {
	sort();
	ready_q->push(p);
}

PCB Scheduler::getNext() {
	PCB temp = ready_q->front();
	ready_q->pop();
	return temp;
}

bool Scheduler::isEmpty() {
	return ready_q->empty();
}

bool Scheduler::time_to_switch_processes(int tick_count, PCB &p) {
	if (p.remaining_cpu_time <= 0) {
		return true;
	}
	if (preemptive) {
		if ((p.required_cpu_time-p.remaining_cpu_time) % time_slice == 0) {
			return true;
		}
		else return false;
	}
	return false;
}
