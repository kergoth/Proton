## Fixes belonging in the main makefile
ifeq ($(WITH_FFMPEG),1)
$(FAUDIO_CONFIGURE_FILES64): $(FFMPEG_OUT64)
$(FAUDIO_CONFIGURE_FILES32): $(FFMPEG_OUT32)
endif

MAKEFILE_DEP =

clean:
	rm -rf $(OBJDIR)/syn-* $(OBJDIR)/obj-* $(OBJDIR)/dist $(OBJDIR)/dist-wine32

# clean-post-dist: dist
# 	rm -rf $(OBJDIR)/syn-* $(OBJDIR)/obj-* $(OBJDIR)/dist-wine32

# ALL_TARGETS += clean-post-dist

CMAKE_FLAGS ?= -GNinja -DCMAKE_BUILD_TYPE=Release -Wno-dev

OBJDIR := $(abspath .)
ABS_SRCDIR := $(abspath $(SRCDIR))
ABS_TOOLS_DIR32 := $(abspath $(TOOLS_DIR32))
ABS_TOOLS_DIR64 := $(abspath $(TOOLS_DIR64))

FREETYPE_SONAME = libprotonfreetype.$(LIB_SUFFIX)
FREETYPE = $(ABS_SRCDIR)/freetype2
FREETYPE_OBJ32 = $(OBJDIR)/obj-freetype32
FREETYPE_OBJ64 = $(OBJDIR)/obj-freetype64
FREETYPE_OUT64 = $(ABS_TOOLS_DIR64)/lib/$(FREETYPE_SONAME)
FREETYPE_OUT32 = $(ABS_TOOLS_DIR32)/lib/$(FREETYPE_SONAME)

LIBPNG_SONAME = libprotonpng16.$(LIB_SUFFIX)
LIBPNG = $(ABS_SRCDIR)/libpng
LIBPNGPROTON = $(OBJDIR)/syn-libpng
LIBPNG_OBJ32 = $(OBJDIR)/obj-libpng32
LIBPNG_OBJ64 = $(OBJDIR)/obj-libpng64
LIBPNG_OUT64 = $(ABS_TOOLS_DIR64)/lib/$(LIBPNG_SONAME)
LIBPNG_OUT32 = $(ABS_TOOLS_DIR32)/lib/$(LIBPNG_SONAME)

LIBJPEG_SONAME = libprotonjpeg.$(LIB_SUFFIX)
LIBJPEG = $(ABS_SRCDIR)/libjpeg-turbo
LIBJPEGPROTON = $(OBJDIR)/syn-libjpeg
LIBJPEG_OBJ32 = $(OBJDIR)/obj-libjpeg32
LIBJPEG_OBJ64 = $(OBJDIR)/obj-libjpeg64
LIBJPEG_OUT64 = $(ABS_TOOLS_DIR64)/lib/$(LIBJPEG_SONAME)
LIBJPEG_OUT32 = $(ABS_TOOLS_DIR32)/lib/$(LIBJPEG_SONAME)

LIBSDL = $(ABS_SRCDIR)/SDL-mirror
LIBSDL_OBJ64 = $(OBJDIR)/obj-libsdl32
LIBSDL_OBJ32 = $(OBJDIR)/obj-libsdl64
LIBSDL_OUT64 = $(ABS_TOOLS_DIR64)/lib/libSDL2.$(LIB_SUFFIX)
LIBSDL_OUT32 = $(ABS_TOOLS_DIR32)/lib/libSDL2.$(LIB_SUFFIX)

MOLTENVK = $(ABS_SRCDIR)/MoltenVK
MOLTENVKPROTON = $(OBJDIR)/syn-moltenvk
MOLTENVK_OBJ = $(OBJDIR)/obj-moltenvk
MOLTENVK_OUT = $(ABS_TOOLS_DIR64)/lib/libMoltenVK.$(LIB_SUFFIX)

LICENSE = $(ABS_SRCDIR)/dist.LICENSE.osx
STRIP = strip -x
LIB_SUFFIX = dylib
WINE32_AUTOCONF = --without-x \
                  ac_cv_lib_soname_freetype=$(FREETYPE_SONAME) \
                  ac_cv_lib_soname_png=$(LIBPNG_SONAME) \
                  ac_cv_lib_soname_jpeg=$(LIBJPEG_SONAME)
WINE64_AUTOCONF = --without-x \
                  ac_cv_lib_soname_freetype=$(FREETYPE_SONAME) \
                  ac_cv_lib_soname_png=$(LIBPNG_SONAME) \
                  ac_cv_lib_soname_jpeg=$(LIBJPEG_SONAME)

XML2_CFLAGS      := $(xml2-config --cflags)
XML2_LIBS        := $(xml2-config --libs)
FREETYPE32_CFLAGS = -I$(ABS_TOOLS_DIR32)/include/freetype2
FREETYPE32_LIBS   = -L$(ABS_TOOLS_DIR32)/lib -lprotonfreetype -framework CoreServices -framework ApplicationServices -lz
FREETYPE64_CFLAGS = -I$(ABS_TOOLS_DIR64)/include/freetype2
FREETYPE64_LIBS   = -L$(ABS_TOOLS_DIR64)/lib -lprotonfreetype
PNG32_CFLAGS      = -I$(ABS_TOOLS_DIR32)/include
PNG32_LIBS        = -L$(ABS_TOOLS_DIR32)/lib -lprotonpng
PNG64_CFLAGS      = -I$(ABS_TOOLS_DIR64)/include
PNG64_LIBS        = -L$(ABS_TOOLS_DIR64)/lib -lprotonpng
JPEG32_CFLAGS     = -I$(ABS_TOOLS_DIR32)/include
JPEG32_LIBS       = -L$(ABS_TOOLS_DIR32)/lib -lprotonjpeg
JPEG64_CFLAGS     = -I$(ABS_TOOLS_DIR64)/include
JPEG64_LIBS       = -L$(ABS_TOOLS_DIR64)/lib -lprotonjpeg

# Quote the new values of the flags vars for the wine builds
$(call QUOTE_VARIABLE_LIST,$(QUOTED_VARIABLES))

##
## freetype
##
FREETYPE_CONFIGURE_FILES32 = $(FREETYPE_OBJ32)/build.ninja
FREETYPE_CONFIGURE_FILES64 = $(FREETYPE_OBJ64)/build.ninja
FREETYPE_SRC_FIXED = $(FREETYPE)/.fixed
FREETYPE_CMAKE_FLAGS = $(CMAKE_FLAGS) \
               -DWITH_PNG=OFF \
               -DWITH_HarfBuzz=OFF \
               -DBUILD_SHARED_LIBS:BOOL=true

$(FREETYPE_SRC_FIXED):
	sed -i -ebak '/protonfreetype/d' $(FREETYPE)/CMakeLists.txt
	echo 'set_target_properties(freetype PROPERTIES OUTPUT_NAME protonfreetype)' >>$(FREETYPE)/CMakeLists.txt
	touch $(FREETYPE_SRC_FIXED)

$(FREETYPE_CONFIGURE_FILES32): $(FREETYPE_SRC_FIXED)
	mkdir -p $(FREETYPE_OBJ32)
	cd $(dir $@) && \
	    $(CMAKE_BIN32) $(FREETYPE) \
	        -DCMAKE_INSTALL_PREFIX="$(ABS_TOOLS_DIR32)" \
	        $(FREETYPE_CMAKE_FLAGS) \
	        -DCMAKE_C_FLAGS="-m32 $(CFLAGS)" -DCMAKE_CXX_FLAGS="-m32 $(CXXFLAGS)" \
	        -DCMAKE_SHARED_LINKER_FLAGS="$(LDFLAGS)"

$(FREETYPE_CONFIGURE_FILES64): $(FREETYPE_SRC_FIXED)
	mkdir -p $(FREETYPE_OBJ64)
	cd $(dir $@) && \
	    $(CMAKE_BIN64) $(FREETYPE) \
	        -DCMAKE_INSTALL_PREFIX="$(ABS_TOOLS_DIR64)" \
	        $(FREETYPE_CMAKE_FLAGS) \
	        -DCMAKE_C_FLAGS="$(CFLAGS)" -DCMAKE_CXX_FLAGS="$(CXXFLAGS)" \
	        -DCMAKE_SHARED_LINKER_FLAGS="$(LDFLAGS)"

$(FREETYPE_OUT32): $(FREETYPE_CONFIGURE_FILES32)
	ninja -C $(FREETYPE_OBJ32) install
	mkdir -p $(DST_DIR)/lib
	cp $(FREETYPE_OUT32) $(DST_DIR)/lib
	install_name_tool -id $(ABS_TOOLS_DIR32)/lib/$(FREETYPE_SONAME) $(FREETYPE_OUT32)
	[ x"$(STRIP)" = x ] || $(STRIP) $(DST_DIR)/lib/$(FREETYPE_SONAME)

$(FREETYPE_OUT64): $(FREETYPE_CONFIGURE_FILES64)
	ninja -C $(FREETYPE_OBJ64) install
	mkdir -p $(DST_DIR)/lib64
	cp $(FREETYPE_OUT64) $(DST_DIR)/lib64
	install_name_tool -id $(ABS_TOOLS_DIR64)/lib/$(FREETYPE_SONAME) $(FREETYPE_OUT64)
	[ x"$(STRIP)" = x ] || $(STRIP) $(DST_DIR)/lib64/$(FREETYPE_SONAME)

## Freetype goals
FREETYPE_TARGETS = freetype freetype32 freetype64 freetype_autogen freetype_configure freetype_configure32 freetype_configure64

GOAL_TARGETS_LIBS += freetype

.PHONY: $(FREETYPE_TARGETS)

freetype_configure: $(FREETYPE_CONFIGURE_FILES32) $(FREETYPE_CONFIGURE_FILES64)
freetype_configure64: $(FREETYPE_CONFIGURE_FILES64)
freetype_configure32: $(FREETYPE_CONFIGURE_FILES32)
freetype_autogen: $(FREETYPE_AUTOGEN_FILES)
freetype: freetype32 freetype64
freetype64: $(FREETYPE_OUT64)
freetype32: $(FREETYPE_OUT32)

##
## libpng
##
LIBPNG_SRC_FIXED = $(LIBPNGPROTON)/.fixed
LIBPNG_CONFIGURE_FILES32 = $(LIBPNG_OBJ32)/build.ninja
LIBPNG_CONFIGURE_FILES64 = $(LIBPNG_OBJ64)/build.ninja
LIBPNG_CMAKE_FLAGS = $(CMAKE_FLAGS) \
	         -DPNG_SHARED=ON \
	         -DPNG_STATIC=OFF

$(LIBPNG_SRC_FIXED):
	rm -rf $(LIBPNGPROTON)
	mkdir -p $(LIBPNGPROTON)
	cd $(LIBPNGPROTON) && ln -sf $(LIBPNG)/* .
	rm $(LIBPNGPROTON)/CMakeLists.txt
	cp $(LIBPNG)/CMakeLists.txt $(LIBPNGPROTON)/
	sed -i -ebak 's/^set(PNG_LIB_NAME png/set(PNG_LIB_NAME protonpng/' $(LIBPNGPROTON)/CMakeLists.txt
	touch $(LIBPNG_SRC_FIXED)

$(LIBPNG_CONFIGURE_FILES32): $(LIBPNG_SRC_FIXED)
	mkdir -p $(LIBPNG_OBJ32)
	cd $(dir $@) && \
	    $(CMAKE_BIN32) $(LIBPNGPROTON) \
	        -DCMAKE_INSTALL_PREFIX="$(ABS_TOOLS_DIR32)" \
	        $(LIBPNG_CMAKE_FLAGS) \
	        -DCMAKE_C_FLAGS="-m32 $(CFLAGS)" \
	        -DCMAKE_SHARED_LINKER_FLAGS="$(LDFLAGS)"

$(LIBPNG_CONFIGURE_FILES64): $(LIBPNG_SRC_FIXED)
	mkdir -p $(LIBPNG_OBJ64)
	cd $(dir $@) && \
	    $(CMAKE_BIN64) $(LIBPNGPROTON) \
	        -DCMAKE_INSTALL_PREFIX="$(ABS_TOOLS_DIR64)" \
	        $(LIBPNG_CMAKE_FLAGS) \
	        -DCMAKE_C_FLAGS="$(CFLAGS)" \
	        -DCMAKE_SHARED_LINKER_FLAGS="$(LDFLAGS)"

$(LIBPNG_OUT32): $(LIBPNG_CONFIGURE_FILES32)
	ninja -C $(LIBPNG_OBJ32) install
	mkdir -p $(DST_DIR)/lib
	cp $(LIBPNG_OUT32) $(DST_DIR)/lib
	[ x"$(STRIP)" = x ] || $(STRIP) $(DST_DIR)/lib/$(LIBPNG_SONAME)

$(LIBPNG_OUT64): $(LIBPNG_CONFIGURE_FILES64)
	ninja -C $(LIBPNG_OBJ64) install
	mkdir -p $(DST_DIR)/lib64
	cp $(LIBPNG_OUT64) $(DST_DIR)/lib64
	[ x"$(STRIP)" = x ] || $(STRIP) $(DST_DIR)/lib64/$(LIBPNG_SONAME)

## Libpng goals
LIBPNG_TARGETS = libpng libpng32 libpng64 libpng_autogen libpng_configure libpng_configure32 libpng_configure64

GOAL_TARGETS_LIBS += libpng

.PHONY: $(LIBPNG_TARGETS)

libpng_configure: $(LIBPNG_CONFIGURE_FILES32) $(LIBPNG_CONFIGURE_FILES64)
libpng_configure64: $(LIBPNG_CONFIGURE_FILES64)
libpng_configure32: $(LIBPNG_CONFIGURE_FILES32)
libpng_autogen: $(LIBPNG_AUTOGEN_FILES)
libpng: libpng32 libpng64
libpng64: $(LIBPNG_OUT64)
libpng32: $(LIBPNG_OUT32)

##
## libjpeg
##
LIBJPEG_SRC_FIXED = $(LIBJPEGPROTON)/.fixed
LIBJPEG_CONFIGURE_FILES32 = $(LIBJPEG_OBJ32)/build.ninja
LIBJPEG_CONFIGURE_FILES64 = $(LIBJPEG_OBJ64)/build.ninja
LIBJPEG_CMAKE_FLAGS = $(CMAKE_FLAGS) \
	          -DENABLE_STATIC:BOOL=false \
	          -DCMAKE_POSITION_INDEPENDENT_CODE=1 \
	          -DREQUIRE_SIMD=1

$(LIBJPEG_SRC_FIXED):
	rm -rf $(LIBJPEGPROTON)
	mkdir -p $(LIBJPEGPROTON)
	cd $(LIBJPEGPROTON) && ln -sf $(LIBJPEG)/* .
	rm $(LIBJPEGPROTON)/CMakeLists.txt
	cp -a $(LIBJPEG)/CMakeLists.txt $(LIBJPEGPROTON)/
	echo 'set_target_properties(jpeg PROPERTIES OUTPUT_NAME protonjpeg)' >>$(LIBJPEGPROTON)/CMakeLists.txt
	touch $(LIBJPEG_SRC_FIXED)

$(LIBJPEG_CONFIGURE_FILES32): $(LIBJPEG_SRC_FIXED)
	mkdir -p $(LIBJPEG_OBJ32)
	cd $(dir $@) && \
	    $(CMAKE_BIN32) $(LIBJPEGPROTON) \
	        -DCMAKE_INSTALL_PREFIX="$(ABS_TOOLS_DIR32)" \
	        $(LIBJPEG_CMAKE_FLAGS) \
	        -DCMAKE_C_FLAGS="-m32 $(CFLAGS)" \
	        -DCMAKE_SHARED_LINKER_FLAGS="$(LDFLAGS)"

$(LIBJPEG_CONFIGURE_FILES64): $(LIBJPEG_SRC_FIXED)
	mkdir -p $(LIBJPEG_OBJ64)
	cd $(dir $@) && \
	    $(CMAKE_BIN64) $(LIBJPEGPROTON) \
	        -DCMAKE_INSTALL_PREFIX="$(ABS_TOOLS_DIR64)" \
	        $(LIBJPEG_CMAKE_FLAGS) \
	        -DCMAKE_C_FLAGS="$(CFLAGS)" \
	        -DCMAKE_SHARED_LINKER_FLAGS="$(LDFLAGS)"

$(LIBJPEG_OUT32): $(LIBJPEG_CONFIGURE_FILES32)
	ninja -C $(LIBJPEG_OBJ32) install
	mkdir -p $(DST_DIR)/lib
	cp $(LIBJPEG_OUT32) $(DST_DIR)/lib
	[ x"$(STRIP)" = x ] || $(STRIP) $(DST_DIR)/lib/$(LIBJPEG_SONAME)

$(LIBJPEG_OUT64): $(LIBJPEG_CONFIGURE_FILES64)
	ninja -C $(LIBJPEG_OBJ64) install
	mkdir -p $(DST_DIR)/lib64
	cp $(LIBJPEG_OUT64) $(DST_DIR)/lib64
	[ x"$(STRIP)" = x ] || $(STRIP) $(DST_DIR)/lib64/$(LIBJPEG_SONAME)

## Libjpeg goals
LIBJPEG_TARGETS = libjpeg libjpeg32 libjpeg64 libjpeg_autogen libjpeg_configure libjpeg_configure32 libjpeg_configure64

GOAL_TARGETS_LIBS += libjpeg

.PHONY: $(LIBJPEG_TARGETS)

libjpeg_configure: $(LIBJPEG_CONFIGURE_FILES32) $(LIBJPEG_CONFIGURE_FILES64)
libjpeg_configure64: $(LIBJPEG_CONFIGURE_FILES64)
libjpeg_configure32: $(LIBJPEG_CONFIGURE_FILES32)
libjpeg_autogen: $(LIBJPEG_AUTOGEN_FILES)
libjpeg: libjpeg32 libjpeg64
libjpeg64: $(LIBJPEG_OUT64)
libjpeg32: $(LIBJPEG_OUT32)

##
## moltenvk
##
$(MOLTENVKPROTON)/.created:
	rm -rf $(MOLTENVKPROTON)
	mkdir -p $(MOLTENVKPROTON)
	ln -sf $(MOLTENVK)/* $(MOLTENVKPROTON)/
	rm -f $(MOLTENVKPROTON)/Package
	ln -s $(MOLTENVK_OBJ)/Package $(MOLTENVKPROTON)/
	touch $(MOLTENVKPROTON)/.created

.PHONY: moltenvk moltenvk-intermediate

GOAL_TARGETS_LIBS += moltenvk

moltenvk: moltenvk-intermediate
moltenvk-intermediate: $(MOLTENVK_OUT)

# The ./fetchDependencies step is not contained within the build directory, but the way it works is very messy to split
# out as such.  We could run it in the symlink'd directory, but then we'd be fetching all of its dependencies per build,
# when they are invariant.  This should still work decently with multiple builds, though perhaps not running them in
# parallel.
$(MOLTENVK_OUT): $(MOLTENVKPROTON)/.created
	cd $(MOLTENVK) && ./fetchDependencies
	mkdir -p $(MOLTENVK_OBJ)/Package
	cd $(MOLTENVKPROTON) && xcodebuild -quiet -project MoltenVKPackaging.xcodeproj -scheme MoltenVK-macOS build -derivedDataPath $(MOLTENVK_OBJ) BUILD_DIR=$(MOLTENVK_OBJ) \
	    CC=$(CC_QUOTED) CXX=$(CXX_QUOTED)

	mkdir -p $(ABS_TOOLS_DIR64)/include $(ABS_TOOLS_DIR64)/lib $(DST_DIR)/lib64
	cp -a $(MOLTENVK_OBJ)/Release/MoltenVK.framework/Headers/* $(ABS_TOOLS_DIR64)/include/
	cp -a $(MOLTENVK_OBJ)/Release/libMoltenVK.$(LIB_SUFFIX) $(ABS_TOOLS_DIR64)/lib/
	cp -a $(MOLTENVK_OBJ)/Release/libMoltenVK.$(LIB_SUFFIX) $(DST_DIR)/lib64/

##
## libsdl
##
$(LIBSDL)/configure: $(LIBSDL)/configure.in $(LIBSDL)/autogen.sh
	cd $(LIBSDL) && ./autogen.sh
	touch $(LIBSDL)/configure

LIBSDL_CONFIGURE_FILES64 = $(LIBSDL_OBJ64)/Makefile
LIBSDL_CONFIGURE_FILES32 = $(LIBSDL_OBJ32)/Makefile

$(LIBSDL_CONFIGURE_FILES64): $(LIBSDL_AUTOGEN_FILES) $(LIBSDL)/configure
	mkdir -p $(LIBSDL_OBJ64)
	cd $(dir $@) && \
	    $(LIBSDL)/configure --prefix=$(ABS_TOOLS_DIR64) --disable-static \
	        CFLAGS="-g -O2 $(CFLAGS)" LDFLAGS="$(LDFLAGS)"

$(LIBSDL_CONFIGURE_FILES32): $(LIBSDL_AUTOGEN_FILES) $(LIBSDL)/configure
	mkdir -p $(LIBSDL_OBJ32)
	cd $(dir $@) && \
	    $(LIBSDL)/configure --prefix=$(ABS_TOOLS_DIR32) --disable-static \
	        CFLAGS="-m32 -g -O2 $(CFLAGS)" LDFLAGS="-m32 $(LDFLAGS)"

$(LIBSDL_OUT64): $(LIBSDL_CONFIGURE_FILES64)
	$(MAKE) -C $(LIBSDL_OBJ64)
	$(MAKE) -C $(LIBSDL_OBJ64) install
	mkdir -p $(DST_DIR)/lib64
	cp $(LIBSDL_OUT64) $(DST_DIR)/lib64/
	$(STRIP) $(DST_DIR)/lib64/libSDL2.$(LIB_SUFFIX)

$(LIBSDL_OUT32): $(LIBSDL_CONFIGURE_FILES32)
	$(MAKE) -C $(LIBSDL_OBJ32)
	$(MAKE) -C $(LIBSDL_OBJ32) install
	mkdir -p $(DST_DIR)/lib
	cp $(LIBSDL_OUT32) $(DST_DIR)/lib/
	$(STRIP) $(DST_DIR)/lib/libSDL2.$(LIB_SUFFIX)

## Libsdl goals
LIBSDL_TARGETS = libsdl libsdl32 libsdl64 libsdl_configure libsdl_configure32 libsdl_configure64

GOAL_TARGETS_LIBS += libsdl

.PHONY: $(LIBSDL_TARGETS)

libsdl_configure: $(LIBSDL_CONFIGURE_FILES)
libsdl_configure64: libsdl_configure
libsdl_configure32: libsdl_configure
libsdl: libsdl32 libsdl64
libsdl64: $(LIBSDL_OUT64)
libsdl32: $(LIBSDL_OUT32)

## Adjustments to targets from the base makefile
$(FAUDIO_CONFIGURE_FILES64): export SDL2_DIR=$(LIBSDL_OBJ64)
$(FAUDIO_CONFIGURE_FILES32): export SDL2_DIR=$(LIBSDL_OBJ32)

$(WINE_CONFIGURE_FILES64): export XML2_CFLAGS := $(XML2_CFLAGS)
$(WINE_CONFIGURE_FILES64): export XML2_LIBS := $(XML2_LIBS)
$(WINE_CONFIGURE_FILES64): export PNG_CFLAGS = $(PNG64_CFLAGS)
$(WINE_CONFIGURE_FILES64): export PNG_LIBS = $(PNG64_LIBS)
$(WINE_CONFIGURE_FILES64): export JPEG_CFLAGS = $(JPEG64_CFLAGS)
$(WINE_CONFIGURE_FILES64): export JPEG_LIBS = $(JPEG64_LIBS)
$(WINE_CONFIGURE_FILES64): export FREETYPE_CFLAGS = $(FREETYPE64_CFLAGS)
$(WINE_CONFIGURE_FILES64): export FREETYPE_LIBS = $(FREETYPE64_LIBS)
$(WINE_CONFIGURE_FILES32): export XML2_CFLAGS := $(XML2_CFLAGS)
$(WINE_CONFIGURE_FILES32): export XML2_LIBS := $(XML2_LIBS)
$(WINE_CONFIGURE_FILES32): export PNG_CFLAGS = $(PNG32_CFLAGS)
$(WINE_CONFIGURE_FILES32): export PNG_LIBS = $(PNG32_LIBS)
$(WINE_CONFIGURE_FILES32): export JPEG_CFLAGS = $(JPEG32_CFLAGS)
$(WINE_CONFIGURE_FILES32): export JPEG_LIBS = $(JPEG32_LIBS)
$(WINE_CONFIGURE_FILES32): export FREETYPE_CFLAGS = $(FREETYPE32_CFLAGS)
$(WINE_CONFIGURE_FILES32): export FREETYPE_LIBS = $(FREETYPE32_LIBS)

# Additional deps for the macOS build
$(FAUDIO_CONFIGURE_FILES64): $(LIBSDL_OUT64)
$(FAUDIO_CONFIGURE_FILES32): $(LIBSDL_OUT32)

ifeq ($(WITH_VKD3D),1)
$(VKD3D_CONFIGURE_FILES64): $(MOLTENVK_OUT)
endif

ifneq ($(NO_DXVK),1)
$(DXVK_CONFIGURE_FILES64): $(MOLTENVK_OUT)
endif

WINE_OSX_DEPS64 = $(FREETYPE_OUT64) $(LIBPNG_OUT64) $(LIBJPEG_OUT64) $(LIBSDL_OUT64) $(MOLTENVK_OUT)
WINE_OSX_DEPS32 = $(FREETYPE_OUT32) $(LIBPNG_OUT32) $(LIBJPEG_OUT32) $(LIBSDL_OUT32) $(MOLTENVK_OUT)

$(WINE_CONFIGURE_FILES64): $(WINE_OSX_DEPS64)
$(WINE_CONFIGURE_FILES32): $(WINE_OSX_DEPS32)

# Fix rpaths for targets from the main makefile
ifeq ($(WITH_FFMPEG),1)

ffmpeg64: $(FFMPEG_OUT64).rpath

$(FFMPEG_OUT64).rpath: $(FFMPEG_OUT64)
	# Use rpath to link to avoid issues locating the libs
	for lib in $(ABS_TOOLS_DIR64)/lib/{libavcodec,libavutil,libswresample}*.*.$(LIB_SUFFIX); do \
	    name=$$(basename $$lib); \
	    install_name_tool -id @rpath/$$name $$lib; \
	    for dep_lib in $(ABS_TOOLS_DIR64)/lib/{libavcodec,libavutil,libswresample}*.*.$(LIB_SUFFIX); do \
	        if [[ "$$lib" != "$$dep_lib" ]]; then \
	            echo >&2 "$$dep_lib: changing $$lib to @rpath/$$name"; \
	            install_name_tool -change "$$lib" "@rpath/$$name" "$$dep_lib"; \
	        fi; \
	    done; \
	done
	cp -L $(TOOLS_DIR64)/lib/{libavcodec,libavutil,libswresample}* $(DST_DIR)/lib64/
	touch $@

ffmpeg32: $(FFMPEG_OUT32).rpath

$(FFMPEG_OUT32).rpath: $(FFMPEG_OUT32)
	# Use rpath to link to avoid issues locating the libs
	for lib in $(ABS_TOOLS_DIR32)/lib/{libavcodec,libavutil,libswresample}*.*.$(LIB_SUFFIX); do \
	    name=$$(basename $$lib); \
	    install_name_tool -id @rpath/$$name $$lib; \
	    for dep_lib in $(ABS_TOOLS_DIR32)/lib/{libavcodec,libavutil,libswresample}*.*.$(LIB_SUFFIX); do \
	        if [[ "$$lib" != "$$dep_lib" ]]; then \
	            echo >&2 "$$dep_lib: changing $$lib to @rpath/$$name"; \
	            install_name_tool -change "$$lib" "@rpath/$$name" "$$dep_lib"; \
	        fi; \
	    done; \
	done
	cp -L $(TOOLS_DIR32)/lib/{libavcodec,libavutil,libswresample}* $(DST_DIR)/lib/
	touch $@

endif # ifeq ($(WITH_FFMPEG),1)

faudio32: $(FAUDIO_OBJ_FILES32).rpath
$(FAUDIO_OBJ_FILES32).rpath: $(FAUDIO_OBJ_FILES32)
	install_name_tool -change "$(ABS_TOOLS_DIR32)/lib/libSDL2-2.0.0.$(LIB_SUFFIX)" "@rpath/libSDL2.$(LIB_SUFFIX)" $(DST_DIR)/lib/libFAudio.$(LIB_SUFFIX)
	touch $@

faudio64: $(FAUDIO_OBJ_FILES64).rpath
$(FAUDIO_OBJ_FILES64).rpath: $(FAUDIO_OBJ_FILES64)
	install_name_tool -change "$(ABS_TOOLS_DIR64)/lib/libSDL2-2.0.0.$(LIB_SUFFIX)" "@rpath/libSDL2.$(LIB_SUFFIX)" $(DST_DIR)/lib64/libFAudio.$(LIB_SUFFIX)
	touch $@

$(FAUDIO_OBJ_FILES32): SHELL = $(CONTAINER_SHELL32)
$(FAUDIO_OBJ_FILES32): $(FAUDIO_CONFIGURE_FILES32)

$(WINE_BUILDTOOLS64) $(WINE_OUT) wine64: $(ABS_TOOLS_DIR64)/.wine-rpath

$(ABS_TOOLS_DIR64)/.wine-rpath: wine64-intermediate
	# Fix SDL library paths
	find $(DST_DIR)/lib64/wine -name dinput\*.dll.so -print0 | \
	    xargs -0 -n 1 install_name_tool -change "$(ABS_TOOLS_DIR64)/lib/libSDL2-2.0.0.$(LIB_SUFFIX)" "@rpath/libSDL2.$(LIB_SUFFIX)"
	touch $@

$(WINE_BUILDTOOLS32) wine32: $(ABS_TOOLS_DIR32)/.wine-rpath

$(ABS_TOOLS_DIR32)/.wine-rpath: wine32-intermediate
	# Fix SDL library paths
	find $(DST_DIR)/lib/wine -name dinput\*.dll.so -print0 | \
	    xargs -0 -n 1 install_name_tool -change "$(ABS_TOOLS_DIR32)/lib/libSDL2-2.0.0.$(LIB_SUFFIX)" "@rpath/libSDL2.$(LIB_SUFFIX)"
	touch $@

