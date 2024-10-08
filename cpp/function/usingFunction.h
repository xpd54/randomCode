#include <initializer_list>
#include <string>
#include <vector>
int printFactorial(int &);
int count_calling();
void printing_with_two_pointer();
void sum_of_value(const int &, const int &, int &);
void print_c_style_char_array(const char *);
void print_array_with_iterator(const int *, const int *);
void error_msg(std::initializer_list<std::string>);
std::string &shorter_string(std::string &, std::string &);
char &get_val(std::string &str, std::string::size_type ix);
int factorial(int val);
/*If there is a default value argument is available it should be defined and
 * declaired into function declaration, And skip that in defination.
 */
void print_vector(const std::vector<int> &, size_t size = 0);
void print_vector(const std::vector<int> &input = {}, size_t);