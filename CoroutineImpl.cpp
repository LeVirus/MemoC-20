#pragma once

module;
//les import doivent être impérativement positionné aprés le "module;"
import <iostream>;
module Coroutine;

//=========================================================
Coroutine::Coroutine() = default;

//=========================================================
void Coroutine::testCor()
{
    std::cerr << "Debut Coroutine\n";
}
