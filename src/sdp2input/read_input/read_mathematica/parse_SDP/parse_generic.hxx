#include "../../Positive_Matrix_With_Prefactor_State.hxx"

#include <algorithm>
#include <iterator>
#include <string>

const char *parse_matrix(const char *begin, const char *end,
                         Positive_Matrix_With_Prefactor &matrix);

const char *
parse_polynomial(const char *begin, const char *end, Polynomial &polynomial);

inline const char *
parse_generic(const char *begin, const char *end, Polynomial &polynomial)
{
  return parse_polynomial(begin, end, polynomial);
}

inline const char *parse_generic(const char *begin, const char *end,
                                 Positive_Matrix_With_Prefactor &matrix)
{
  return parse_matrix(begin, end, matrix);
}

template <typename T>
const char *parse_generic(const char *begin, const char *end,
                          std::vector<T> &result_vector)
{
  const auto open_brace(std::find(begin, end, '{'));
  if(open_brace == end)
    {
      throw std::runtime_error("Could not find '{' to start array");
    }

  auto delimiter(open_brace);
  const std::vector<char> delimiters({',', '}'});
  do
    {
      auto start_matrix(std::next(delimiter));
      result_vector.emplace_back();
      auto end_matrix(parse_generic(start_matrix, end, result_vector.back()));
      delimiter = std::find_first_of(end_matrix, end, delimiters.begin(),
                                     delimiters.end());
      if(delimiter == end)
        {
          throw std::runtime_error("Missing '}' at end of array");
        }
    }
  while(*delimiter != '}');
  return std::next(delimiter);
}
