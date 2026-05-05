all:pthread_return pthread_exit pthread_exit1 pthread_join pthread_detach pthread_cancel pthread_cancel_test pthread_cancel_disable pthread_cancel_any

pthread_return:pthread_return.c
	gcc pthread_return.c -o pthread_return

pthread_exit:pthread_exit.c
	gcc pthread_exit.c -o pthread_exit

pthread_exit1:pthread_exit1.c
	gcc pthread_exit1.c -o pthread_exit1
pthread_join:pthread_join.c
	gcc pthread_join.c -o pthread_join
pthread_detach:pthread_detach.c
	gcc pthread_detach.c -o pthread_detach
pthread_cancel:pthread_cancel.c
	gcc pthread_cancel.c -o pthread_cancel
pthread_cancel_test:pthread_cancel_test.c
	gcc pthread_cancel_test.c -o pthread_cancel_test
pthread_cancel_disable:pthread_cancel_disable.c
	gcc pthread_cancel_disable.c -o pthread_cancel_disable
pthread_cancel_any:pthread_cancel_any.c
	gcc pthread_cancel_any.c -o pthread_cancel_any
clean:
	rm -f pthread_return pthread_exit pthread_exit1