#ifndef DEFS_H
#define DEFS_H

float time_call(int reps, std::function<void(void)> func);
void fill_up_vector(std::vector<float> &arr, long from, long to);
void resample_vector(std::vector<float> &arr, long from, long to, float next);
void print_array(std::vector<float> &arr);

#endif//DEFS_H
