.PHONY: all question1 question2 question3 clean run

all: question1 question2 question3

question1:
	$(MAKE) -C "Question 1"

question2:
	$(MAKE) -C "Question 2"

question3:
	$(MAKE) -C "Question 3"

clean:
	$(MAKE) -C "Question 1" clean
	$(MAKE) -C "Question 2" clean
	$(MAKE) -C "Question 3" clean
	
run:
	cd "Question 1" && $(MAKE) run
	cd "Question 2" && $(MAKE) run
	cd "Question 3" && $(MAKE) run
