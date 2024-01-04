#include"service.h"
#include"Final_Exam_Practical.h"
#include<assert.h>

void test_add()
{
	Service s;
	auto list = s.list2();
	s.add2("Star100", "#1221", 1, 1, 1);
	assert(list.size() == 1);	
}