Iterator = CreateIterator(m);
while(next(i)){
	current(i)
}


void begin(&it it);
void next(&it it);
int current(&it it);
int current_index(&it it)
int jump(&it it)
void delete(&it it)

struct it{
	matrix const* data;
	size_t i;
	size_t j;
	size_t size;
}

*CreateIterator(matrix const&){
	
}

void delete(&it it){
	delete [] it.data;;
	delete &it
}
int current_index(&it it){
	return it.current i 
	return it.current j
}