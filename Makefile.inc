DISTNAME=mlmorph-`cat VERSION`
FSTC ?= hfst
ifeq ($(FSTC),hfst)
%.a: %.fst
	hfst-calculate -w -v -i $< -o $@
else
%.a: %.fst
	fst-compiler-utf8 $< $@
endif