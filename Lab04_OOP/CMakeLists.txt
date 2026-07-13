cmake_minimum_required(VERSION 3.10)
project(MultiProjectGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ==========================================
# BÀI 1: BÀI PHÂN SỐ
# ==========================================
# Tạo ra một ứng dụng tên là "app_phanso"
# add_executable(app_phanso 
#     Fraction.h 
#     Fraction.cpp 
#     main1.cpp         # Chỉ định chính xác file main của phân số
# )

# ==========================================
# BÀI 2: BÀI QUẢN LÝ HERO
# ==========================================
# Tạo ra một ứng dụng tên là "app_hero"
add_executable(app_hero 
    Hero.h 
    Hero.cpp 
    Skill.h 
    Skill.cpp 
    main2.cpp          # Chỉ định chính xác file main của hero
)