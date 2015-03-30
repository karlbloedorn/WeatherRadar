#pragma once
#include <string>
#include <stdio.h>
#include <curl/curl.h>

using namespace std;

class Scan{
	public:
		Scan();
		bool Load(string url);
	private:
};