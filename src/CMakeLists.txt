add_library(libmv mv.c clinfo.c ta.c ta_utils.c)
target_link_libraries(libmv ${OpenCL_LIBRARIES})
