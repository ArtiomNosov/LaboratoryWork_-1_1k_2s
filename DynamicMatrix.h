typedef struct {
	size_t size_of_type;
	size_t lenght;
	void *idata;
	void (*map)();
	void (*where)();
	void (*concat)();
	void (*dump)(void);
} DynamicArray;

DynamicArray* create_DynamicArray(size_t sd, size_t len);

