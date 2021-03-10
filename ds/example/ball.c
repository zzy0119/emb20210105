#include <stdio.h>
#include <stack.h>
#include <queue.h>

static int ballSeq(queue_t *ball)
{
	queue_t *tmp;		
	int cur, next;
	int ret = 1;

	queueInit(sizeof(int), 27, &tmp);

	deq(ball, &cur);
	while (!queueEmpty(ball)) {
		enq(tmp, &cur);
		deq(ball, &next);
		if (next < cur)
			ret = 0;
		cur = next;
	}
	enq(tmp, &cur);

	while (!queueEmpty(tmp)) {
		deq(tmp, &cur);
		enq(ball, &cur);
	}

	queueDestroy(tmp);

	return ret;
}


int main(void)
{
	queue_t *ball;
	stack_t *oneMin;
	stack_t *fiveMin;
	stack_t *oneHour;
	int out, pop;
	int days = 0;

	queueInit(sizeof(int), 27, &ball);
	stackInit(sizeof(int), 4, &oneMin);
	stackInit(sizeof(int), 11, &fiveMin);
	stackInit(sizeof(int), 11, &oneHour);

	for (int i = 1; i <= 27; i++) {
		enq(ball, &i);
	}

	while (1) {
		deq(ball, &out);	
		if (!stackIsFull(oneMin)) {
			stackPush(oneMin, &out);	
		} else {
			while (!stackIsEmpty(oneMin)) {
				stackPop(oneMin, &pop);
				enq(ball, &pop);
			}
			if (!stackIsFull(fiveMin)) 
				stackPush(fiveMin, &out);
			else {
				while (!stackIsEmpty(fiveMin)) {
					stackPop(fiveMin, &pop);
					enq(ball, &pop);
				}
				if (!stackIsFull(oneHour))
					stackPush(oneHour, &out);
				else {
					while (!stackIsEmpty(oneHour)) {
						stackPop(oneHour, &pop);
						enq(ball, &pop);
					}
					enq(ball, &out);
					// 12hour
					days++;
					printf("day:%d\n", days);
					if (ballSeq(ball))
						break;
				}
			}
		}
	}


	printf("经过%d天球的次序有序了\n", days);

	return 0;
}

