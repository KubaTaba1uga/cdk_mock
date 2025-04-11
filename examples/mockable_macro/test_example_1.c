int _main(void);
int add(int a, int b) { return 10; }

int static_add(int a, int b) { return 15; }

void test_main() { _main(); }

int main() { test_main(); }
