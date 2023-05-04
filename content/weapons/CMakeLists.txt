add_library(weapons
  none.cpp
  knife.cpp
  spear.cpp
  cleaver.cpp
  sword.cpp
  sword_rusty.cpp
  sword_red_gem.cpp
  sword_big.cpp
  hammer.cpp
  hammer_big.cpp
  spiked_club.cpp
  mace.cpp
  axe.cpp
  staff_red.cpp
  staff_green.cpp
  )

target_include_directories(weapons PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(weapons PUBLIC engine events)
