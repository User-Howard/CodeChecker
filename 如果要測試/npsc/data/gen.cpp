#include <bits/stdc++.h>
using namespace std;

string exec(string cmd) {
    array<char, 128> buffer;
    string result;
    unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

void write_testdata(string fname, string cont) {
	fname = "secret/" + fname;
	cerr << "write_testdata: " << fname << endl;
	ofstream of(fname + ".in");
	of << cont;
	of.close();
	cerr << "generate solution: " << fname << endl;
	exec("./sol < " + fname + ".in > " + fname + ".ans");
	cerr << "write_testdata: " << fname << " [finish]" << endl;
}

mt19937 mt(7122);
uniform_int_distribution<uint32_t> unif(0, UINT_MAX);
uint32_t rnd() {
	return unif(mt);
}

set<int> generated;

void m_shuffle(vector<int> &v) {
	for (int i = 1; i < (int)v.size(); ++i) swap(v[i], v[rnd() % i]);
}

string normal() {
	int l = 2020, r = 2999;
	int x = rnd() % (r - l + 1) + l;
	if (generated.count(x)) return normal();
	generated.insert(x);
	return to_string(x) + "\n";
}

string special() {
	int l = 2020, r = 2999;
	int x = 2020;
	while (x % 20 != 18) x = rnd() % (r - l + 1) + l;
	if (generated.count(x)) return special();
	generated.insert(x);
	return to_string(x) + "\n";
}

int main() {
	for (int i = 2020; i <= 2060; ++i) {
		generated.insert(i);
		write_testdata(to_string(i), to_string(i) + "\n"s);
	}
	for (int i = 0; i < 20; ++i) {
		write_testdata("normal"s + to_string(i), normal());
		write_testdata("special"s + to_string(i), special());
	}
}
