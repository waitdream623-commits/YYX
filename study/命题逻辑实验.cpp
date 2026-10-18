#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <cctype>

#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#endif

using namespace std;

void replace_all(string& text, const string& from, const string& to)
{
    size_t position = 0;
    while((position = text.find(from, position)) != string::npos)
    {
        text.replace(position, from.size(), to);
        position += to.size();
    }
}

string normalize(string text)
{
    if(text.compare(0, 3, "\xEF\xBB\xBF") == 0)text.erase(0, 3);
    replace_all(text, "&amp;", "&");
    replace_all(text, "&nbsp;", " ");
    replace_all(text, "&and;", "&");
    replace_all(text, "&or;", "|");
    replace_all(text, "&not;", "!");
    replace_all(text, "&rarr;", ">");
    replace_all(text, "&rArr;", "=>");
    replace_all(text, "&gt;", ">");
    replace_all(text, "&#708;", "&");
    replace_all(text, "&#8743;", "&");
    replace_all(text, "&#709;", "|");
    replace_all(text, "&#8744;", "|");
    replace_all(text, "&#8594;", ">");
    replace_all(text, "&#8658;", "=>");
    replace_all(text, "&#x2227;", "&");
    replace_all(text, "&#x2228;", "|");
    replace_all(text, "&#x00AC;", "!");
    replace_all(text, "&#x2192;", ">");
    replace_all(text, "&#x21D2;", "=>");
    replace_all(text, "\xC2\xA0", " ");
    replace_all(text, "　", " ");

    replace_all(text, "∧", "&");
    replace_all(text, "˄", "&");
    replace_all(text, "∨", "|");
    replace_all(text, "˅", "|");
    replace_all(text, "¬", "!");
    replace_all(text, "→", ">");
    replace_all(text, "⇒", "=>");
    replace_all(text, "->", ">");
    replace_all(text, "，", ",");
    replace_all(text, "；", ";");
    replace_all(text, "（", "(");
    replace_all(text, "）", ")");

    string result;
    for(unsigned char symbol : text)
    {
        if(isspace(symbol))continue;

        if(symbol == '~')symbol = '!';
        if(symbol == '^')symbol = '&';
        if(symbol >= 'A' && symbol <= 'Z')
            symbol = symbol - 'A' + 'a';

        result += char(symbol);
    }
    return result;
}

int extract_mode(string& text)
{
    if(text.size() < 4 || text[0] != '(' || text[2] != ')')return 0;
    if(text[1] < '0' || text[1] > '9')return 0;

    char next = text[3];
    bool startsFormula = (next >= 'a' && next <= 'z') || next == '0' || next == '1' ||
                         next == '!' || next == '(';
    if(!startsFormula)return 0;

    int mode = text[1] - '0';
    text.erase(0, 3);
    return mode >= 1 && mode <= 5 ? mode : -1;
}

struct Node
{
    char symbol;
    int left, right;
};

struct Formula
{
    string text;
    vector<Node> nodes;
    int position = 0;
    int root = -1;

    int add_node(char symbol, int left = -1, int right = -1)
    {
        nodes.push_back({symbol, left, right});
        return int(nodes.size()) - 1;
    }

    int parse_unary()
    {
        if(position >= int(text.size()))return -1;
        char symbol = text[position];

        if((symbol >= 'a' && symbol <= 'z') ||
           symbol == '0' || symbol == '1')
        {
            position++;
            return add_node(symbol);
        }

        if(symbol == '!')
        {
            position++;
            int child = parse_unary();
            if(child == -1)return -1;
            return add_node('!', child);
        }

        if(symbol == '(')
        {
            position++;
            int child = parse_implication();

            if(child == -1)return -1;
            if(position >= int(text.size()))return -1;
            if(text[position] != ')')return -1;

            position++;
            return child;
        }

        return -1;
    }

    int parse_and()
    {
        int current = parse_unary();
        if(current == -1)return -1;

        while(position < int(text.size()) && text[position] == '&')
        {
            position++;
            int right = parse_unary();
            if(right == -1)return -1;
            current = add_node('&', current, right);
        }
        return current;
    }

    int parse_or()
    {
        int current = parse_and();
        if(current == -1)return -1;

        while(position < int(text.size()) && text[position] == '|')
        {
            position++;
            int right = parse_and();
            if(right == -1)return -1;
            current = add_node('|', current, right);
        }
        return current;
    }

    int parse_implication()
    {
        int current = parse_or();
        if(current == -1)return -1;

        if(position < int(text.size()) && text[position] == '>')
        {
            position++;
            int right = parse_implication();
            if(right == -1)return -1;
            current = add_node('>', current, right);
        }
        return current;
    }

    bool build(const string& input)
    {
        text = input;
        nodes.clear();
        position = 0;
        root = -1;

        if(text.empty() || text.size() > 255)return false;

        root = parse_implication();
        return root != -1 && position == int(text.size());
    }

    int evaluate(int nodeId, const array<int, 26>& values) const
    {
        const Node& node = nodes[nodeId];

        if(node.symbol >= 'a' && node.symbol <= 'z')
            return values[node.symbol - 'a'];

        if(node.symbol == '0' || node.symbol == '1')
            return node.symbol - '0';

        int leftValue = evaluate(node.left, values);

        if(node.symbol == '!')return !leftValue;

        int rightValue = evaluate(node.right, values);

        if(node.symbol == '&')return leftValue && rightValue;
        if(node.symbol == '|')return leftValue || rightValue;

        return !leftValue || rightValue;
    }
};

bool build_inference(const string& text, Formula& formula)
{
    size_t separator = text.find("=>");
    if(separator == string::npos)
    {
        return formula.build(text) && formula.nodes[formula.root].symbol == '>';
    }
    if(text.find("=>", separator + 2) != string::npos)return false;

    string premises = text.substr(0, separator);
    string conclusion = text.substr(separator + 2);
    if(!premises.empty() && (premises.back() == ',' || premises.back() == ';'))
        premises.pop_back();
    if(premises.empty() || conclusion.empty())return false;

    replace(premises.begin(), premises.end(), ';', ',');
    string antecedent;
    size_t start = 0;
    while(true)
    {
        size_t end = premises.find(',', start);
        string premise = premises.substr(start, end == string::npos ? end : end - start);
        Formula checked;
        if(!checked.build(premise))return false;

        if(antecedent.empty())antecedent = "(" + premise + ")";
        else antecedent = "(" + antecedent + "&(" + premise + "))";

        if(end == string::npos)break;
        start = end + 1;
    }

    Formula checked;
    if(!checked.build(conclusion))return false;
    return formula.build("(" + antecedent + ">(" + conclusion + "))");
}

vector<int> get_variables(const string& text)
{
    array<bool, 26> used{};

    for(char symbol : text)
    {
        if(symbol >= 'a' && symbol <= 'z')
            used[symbol - 'a'] = true;
    }

    vector<int> variables;
    for(int index = 0; index < 26; index++)
    {
        if(used[index])variables.push_back(index);
    }
    return variables;
}

array<int, 26> get_values(int row, const vector<int>& variables)
{
    array<int, 26> values{};

    for(int index = 0; index < int(variables.size()); index++)
    {
        int shift = int(variables.size()) - index - 1;
        values[variables[index]] = (row >> shift) & 1;
    }
    return values;
}

vector<int> get_results(const Formula& formula,
                        const vector<int>& variables)
{
    int rows = 1 << int(variables.size());
    vector<int> results(rows);

    for(int row = 0; row < rows; row++)
    {
        auto values = get_values(row, variables);
        results[row] = formula.evaluate(formula.root, values);
    }
    return results;
}

void print_table(const vector<int>& variables,
                 const vector<int>& first,
                 const vector<int>& second = {})
{
    for(int variable : variables)
        cout << char('A' + variable) << ' ';

    cout << (second.empty() ? "| F\n" : "| A B\n");

    for(int row = 0; row < int(first.size()); row++)
    {
        auto values = get_values(row, variables);

        for(int variable : variables)
            cout << values[variable] << ' ';

        cout << "| " << first[row];

        if(!second.empty())cout << ' ' << second[row];

        cout << '\n';
    }
}

void print_normal_form(const vector<int>& results,
                       const vector<int>& variables,
                       int target,
                       bool encoded = false,
                       const string& suffix = "")
{
    if(variables.empty())
    {
        cout << results[0] << suffix << '\n';
        return;
    }

    int terms = int(count(results.begin(), results.end(), target));
    bool parentheses = !encoded || terms > 1;
    bool firstTerm = true;

    for(int row = 0; row < int(results.size()); row++)
    {
        if(results[row] != target)continue;

        if(!firstTerm)
        {
            if(encoded)cout << (target == 1 ? "&#709;" : "&#708;");
            else cout << (target == 1 ? " | " : " & ");
        }
        firstTerm = false;

        auto values = get_values(row, variables);
        if(parentheses)cout << '(';

        for(int index = 0; index < int(variables.size()); index++)
        {
            if(index > 0)
            {
                if(encoded)cout << (target == 1 ? "&#708;" : "&#709;");
                else cout << (target == 1 ? " & " : " | ");
            }

            int variable = variables[index];

            if(values[variable] != target)cout << '~';

            cout << char('A' + variable);
        }

        if(parentheses)cout << ')';
    }

    if(firstTerm)cout << (target == 1 ? '0' : '1');

    cout << suffix << '\n';
}

void print_assignment(int row, const vector<int>& variables)
{
    if(variables.empty())
    {
        cout << "无变量，公式由常量组成\n";
        return;
    }

    auto values = get_values(row, variables);

    for(int index = 0; index < int(variables.size()); index++)
    {
        if(index > 0)cout << ", ";

        int variable = variables[index];
        cout << char('A' + variable) << '=' << values[variable];
    }
    cout << '\n';
}

void print_category(const vector<int>& results)
{
    int trueCount = int(count(results.begin(), results.end(), 1));
    if(trueCount == int(results.size()))
        cout << "永真式，也是可满足式\n";
    else if(trueCount == 0)
        cout << "永假式或矛盾式\n";
    else
        cout << "偶然式，可满足但非永真\n";
}

void print_inference(const vector<int>& results, const vector<int>& variables)
{
    for(int row = 0; row < int(results.size()); row++)
    {
        if(results[row] == 0)
        {
            cout << "推理无效，前提真、结论假的反例：";
            print_assignment(row, variables);
            return;
        }
    }
    cout << "推理有效\n";
}

void analyze_formula(const Formula& formula,
                     const vector<int>& variables)
{
    auto results = get_results(formula, variables);

    cout << "真值表：\n";
    print_table(variables, results);

    cout << "类别：";
    print_category(results);

    cout << "主析取范式：";
    print_normal_form(results, variables, 1);

    cout << "主合取范式：";
    print_normal_form(results, variables, 0);

    if(formula.nodes[formula.root].symbol == '>')
    {
        cout << "将最外层解释为“前提推出结论”：\n";
        print_inference(results, variables);
    }
}

void compare_formulas(const Formula& first,
                      const Formula& second,
                      const vector<int>& variables,
                      bool showTable = true)
{
    auto firstResults = get_results(first, variables);
    auto secondResults = get_results(second, variables);

    if(showTable)
    {
        cout << "两个公式的真值表：\n";
        print_table(variables, firstResults, secondResults);
    }

    int firstCounter = -1, secondCounter = -1;

    for(int row = 0; row < int(firstResults.size()); row++)
    {
        if(firstResults[row] == 1 &&
           secondResults[row] == 0 && firstCounter == -1)
            firstCounter = row;

        if(secondResults[row] == 1 &&
           firstResults[row] == 0 && secondCounter == -1)
            secondCounter = row;
    }

    cout << "A 蕴含 B：" << (firstCounter == -1 ? "是" : "否") << '\n';
    cout << "B 蕴含 A：" << (secondCounter == -1 ? "是" : "否") << '\n';

    cout << "A 与 B 等价："
         << (firstCounter == -1 && secondCounter == -1 ? "是" : "否")
         << '\n';

    if(firstCounter != -1)
    {
        cout << "A 真、B 假的反例：";
        print_assignment(firstCounter, variables);
    }

    if(secondCounter != -1)
    {
        cout << "B 真、A 假的反例：";
        print_assignment(secondCounter, variables);
    }
}

int main(int argc, char* argv[])
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bool fullOutput = false;
    for(int index = 1; index < argc; index++)
    {
        if(string(argv[index]) == "--full")fullOutput = true;
        else
        {
            cerr << "未知参数；完整实验模式请使用 --full\n";
            return 1;
        }
    }

    string input;

    while(getline(cin, input))
    {
        string text = normalize(input);

        if(text.empty())continue;
        if(text == "exit")break;

        int mode = extract_mode(text);
        if(mode == -1)
        {
            cout << "功能编号必须是 1 到 5。\n";
            continue;
        }
        bool judgeOutput = !fullOutput && mode != 0;
        if(judgeOutput && mode >= 3)
        {
            if(mode == 3)cout << "（3）\n";
            continue;
        }
        if(judgeOutput)
        {
            cout << "（" << mode << "）";
            if(mode == 1)cout << ' ';
        }
        else if(mode != 0)cout << '(' << mode << ") ";
        Formula first, second;

        if(mode == 5 || (mode == 0 && text.find("=>") != string::npos))
        {
            if(!build_inference(text, first))
            {
                cout << "推理式不合法，请使用前提1,前提2=>结论或(前提>结论)。\n";
                continue;
            }
            auto variables = get_variables(first.text);
            if(variables.size() > 8)
            {
                cout << "最多支持 8 个不同变量。\n";
                continue;
            }
            print_inference(get_results(first, variables), variables);
        }
        else if(mode == 4 || (mode == 0 && text.find_first_of(",;") != string::npos))
        {
            size_t separator = text.find_first_of(",;");
            if(separator == string::npos || text.find_first_of(",;", separator + 1) != string::npos)
            {
                cout << "比较时需要两个公式，用一个逗号或分号分隔。\n";
                continue;
            }

            string left = text.substr(0, separator);
            string right = text.substr(separator + 1);
            if(!first.build(left) || !second.build(right))
            {
                cout << "比较公式中存在不合法的表达式。\n";
                continue;
            }
            auto variables = get_variables(first.text + second.text);
            if(variables.size() > 8)
            {
                cout << "两个公式合计最多支持 8 个不同变量。\n";
                continue;
            }
            compare_formulas(first, second, variables, mode == 0);
        }
        else
        {
            if(!first.build(text))
            {
                cout << "公式不合法。\n";
                continue;
            }

            auto variables = get_variables(first.text);

            if(variables.size() > 8)
            {
                cout << "最多支持 8 个不同变量。\n";
                continue;
            }

            auto results = get_results(first, variables);
            if(mode == 1)
            {
                print_normal_form(results, variables, 1, true,
                                  judgeOutput ? "  主析取范式" : " 主析取范式");
            }
            else if(mode == 2)
            {
                print_category(results);
            }
            else if(mode == 3)
            {
                cout << "主析取范式：";
                print_normal_form(results, variables, 1);
                cout << "主合取范式：";
                print_normal_form(results, variables, 0);
            }
            else analyze_formula(first, variables);
        }

        if(!judgeOutput)cout << '\n';
    }

    return 0;
}
