#ifndef DEFS_H
#define DEFS_H

void time_call(int reps, std::function<void(void)> func);
void fill_up_vector(std::vector<float> &arr, long from, long to);

#endif//DEFS_H
