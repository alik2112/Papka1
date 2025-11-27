#include <iostream>
#include <string>

void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}
std::string a = "\n", b= "\\n", c = "\\", d = "\\\\", e = "\"", f = "\\\"";

int main(){
    std::string s = "#include <iostream>\n#include <string>\n\nvoid replaceAll(std::string& str, const std::string& from, const std::string& to) {\n    size_t start_pos = 0;\n    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {\n        str.replace(start_pos, from.length(), to);\n        start_pos += to.length();\n    }\n}\nstd::string a = \"\\n\", b= \"\\\\n\", c = \"\\\\\", d = \"\\\\\\\\\", e = \"\\\"\", f = \"\\\\\\\"\";\n\nint main(){\n    std::string s = \"\";\n    std::string t = s;\n    replaceAll(t, c, d);\n    replaceAll(t, a, b);\n    replaceAll(t, e, f);\n    std::cout << s.substr(0, 427) << t << s.substr(427) << std::endl;\n    return 0;\n}";
    std::string t = s;
    replaceAll(t, c, d);
    replaceAll(t, a, b);
    replaceAll(t, e, f);
    std::cout << s.substr(0, 427) << t << s.substr(427) << std::endl;
    return 0;
}

