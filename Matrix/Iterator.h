#pragma once
struct It;
void begin(&It it);
void next(&It it);
int current(&It it);
int current_index(&It it);
int setto(&It it);
void deleteIterator(&It it);