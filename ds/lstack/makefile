
# 变量
LDFLAGS=-lmylist
LDPATH=-L/home/emb0105/emb20210105/ds/llist
CFLAGS+=-I/home/emb0105/emb20210105/ds/llist
# 目标:依赖
lstack:main.o lstack.o
	@gcc -o $@ $^ $(LDFLAGS) $(LDPATH)
#gcc -o lstack main.o lstack.o $(LDFLAGS) $(LDPATH)
# 规则

main.o:main.c
	@gcc -c -o $@ $^ $(CFLAGS)

lstack.o:lstack.c
	@gcc -c -o $@ $^ $(LDFLAGS) $(LDPATH) $(CFLAGS)

# 伪目标
clean:
	rm *.o	

test:
	echo "逗你玩"


