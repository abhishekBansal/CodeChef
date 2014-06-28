cmake_minimum_required(VERSION 2.6)
project(CodeChefProblems)

#There are lots of scripts with cmake
#for finding external libraries. 
#see /usr/local/share/cmake-2.6/Modules/Find*.cmake for more examples
#find_package(GLUT)
#find_package(OpenGL)

#set(CMAKE_CXX_FLAGS "")
add_subdirectory(NoOfPalindromes_Easy)
add_subdirectory(FierceBattles_Easy)
add_subdirectory(BinaryTreeProduct_Easy)
add_subdirectory(ShortestPathBinTree_Easy)
add_subdirectory(AnswerToLifeUniverseAndEverything_Easy) 
add_subdirectory(EnormousInputTest_Easy) 
add_subdirectory(HolesInText_Easy) 
add_subdirectory(AmbiguousPermutations_Easy)
add_subdirectory(BirthdayCandles_Easy)

