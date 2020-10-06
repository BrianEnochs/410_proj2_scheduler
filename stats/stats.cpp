/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

//TODO fill in content
#include "../includes/stats.h"
#include <iostream>

using namespace std;

Stats::Stats(vector<PCB> &finished_vector) {
	vec = &finished_vector;
	av_response_time = UNINITIALIZED;
	av_wait_time = UNINITIALIZED;
	av_turnaround_time = UNINITIALIZED;
}

void Stats::showAllProcessInfo() {
	vector <PCB>::iterator iter;
	for (iter = vec->begin(); iter != vec->end(); iter++) {
		cout << "Process " << (*iter).process_number << " Required CPU time:" << (*iter).required_cpu_time << "  arrived:" << (*iter).arrival_time <<
				" started:" << (*iter).start_time << " finished:" << (*iter).finish_time << endl;
	}
}

float Stats::get_av_response_time() {
	if (av_response_time == UNINITIALIZED) {
		calcStats();
	}
	return av_response_time;
}

float Stats::get_av_wait_time() {
	if (av_wait_time == UNINITIALIZED) {
		calcStats();
	}
	return av_wait_time;
}

float Stats::get_av_turnaround_time() {
	if (av_turnaround_time == UNINITIALIZED) {
		calcStats();
	}
	return av_turnaround_time;
}

void Stats::calcStats() {
	float turnaround = 0;
	float wait = 0;
	float response = 0;
	vector <PCB>::iterator iter;
	for (iter = vec->begin(); iter != vec->end(); iter++) {
		turnaround += ((*iter).finish_time - (*iter).arrival_time);
		wait += ((*iter).finish_time - (*iter).arrival_time - (*iter).required_cpu_time);
		response += ((*iter).start_time - (*iter).arrival_time);
	}

	av_wait_time = (wait/vec->size());
	av_turnaround_time = (turnaround/vec->size());
	av_response_time = (response/vec->size());
}
