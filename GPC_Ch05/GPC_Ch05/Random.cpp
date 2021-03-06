//
//  Random.cpp
//  GPC_Ch05
//
//  Created by Inoue Shinichi on 2022/06/29.
//

#include "Random.hpp"

void Random::Init()
{
    std::random_device rd; // 完全ランダムなシードを作れる
    Random::Seed(rd());
}

void Random::Seed(unsigned int seed)
{
    sGenerator.seed(seed);
}

float Random::GetFloat()
{
    return GetFloatRange(0.0f, 1.0f);
}

float Random::GetFloatRange(float min, float max)
{
    std::uniform_real_distribution<float> dist(min, max);
    return dist(sGenerator);
}

int Random::GetIntRange(int min, int max)
{
    std::uniform_int_distribution<int> dist(min, max);
    return dist(sGenerator);
}

Vector2 Random::GetVector(const Vector2& min, const Vector2& max)
{
    Vector2 r = Vector2(GetFloat(), GetFloat());
    return min + (max - min) * r;
}

std::mt19937_64 Random::sGenerator;
