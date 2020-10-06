/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

//TODO fill in content
#include "../includes/scheduler_SRTF.h"
#include <algorithm>
#include <vector>

//using namespace std;

bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {
	sort();
	if (p.remaining_cpu_time <= 0) {
		return true;
	}
	if (p.remaining_cpu_time > ready_q->front().remaining_cpu_time) {
		return true;
	}
	return false;
}

void Scheduler_SRTF::sort() {
	std::vector<PCB> temp;
	while (!ready_q->empty()) {
		temp.push_back(ready_q->front());
		ready_q->pop();
	}

	std::sort(temp.begin(), temp.end(),
			[](const PCB &left, const PCB &right)
			{return (left.remaining_cpu_time < right.remaining_cpu_time);});

	std::vector <PCB>::iterator iter;
	for (iter = temp.begin(); iter != temp.end(); iter++) {
		ready_q->push(*iter);
	}
}
