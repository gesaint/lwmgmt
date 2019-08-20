SUBDIRS = ./ext ./service ./data_cache ./tcp_server ./virt_driver ./node ./logs
 
.PHONY: all
all:
	@list='$(SUBDIRS)'; for subdir in $$list; do \
		echo "Make in $$subdir";\
		$(MAKE) -C $$subdir;\
	done

	$(MAKE) -f Makefile.lwmgmt

.PHONY: clean
clean:
	@echo Making clean
	@list='$(SUBDIRS)'; for subdir in $$list; do \
		echo "Clean in $$subdir";\
		$(MAKE) -C $$subdir clean;\
	done

	$(MAKE) clean -f Makefile.lwmgmt
