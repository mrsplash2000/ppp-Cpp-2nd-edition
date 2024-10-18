#pragma once

namespace challenge_ds {

    template<typename T>
    T& max(const Vector<T>& a) {
        size_t idx_max = 0;
        T tmp = a[0];
        for (size_t i=1; i < a.size(); ++i) {
            if (a[i] > tmp) {
                tmp = a[i];
                idx_max = i;
            }
        }
        return a[idx_max];
    }

    template<typename T>
    T& min(const Vector<T>& a) {
        size_t idx_min = 0;
        T tmp = a[0];
        for (size_t i=1; i < a.size(); ++i) {
            if (a[i] < tmp) {
                tmp = a[i];
                idx_min = i;
            }
        }
        return a[idx_min];
    }

    template<typename T>
    T sum(const Vector<T>& a) {
        T total{};
        for (T e : a) {
            total += e;
        }
        return total;
    }

    template<typename T>
    T avg(const Vector<T>& a) {
        return sum(a) / static_cast<double>(a.size());
    }

    template<typename T>
    const std::optional<std::pair<size_t,size_t>>& find(const Vector<T>& a, const T& x) {
        static std::optional<std::pair<size_t, size_t>> result;
        for (size_t i=0; i < a.size(); ++i) {
            if (a[i] == x) {
                result = std::make_optional(std::pair<size_t, size_t>(i, x));
                return result;
            };
        }
        result = std::nullopt;
        return result;
    }

    template<typename T>
    Iterator<T> find(Iterator<T> a, Iterator<T> b, const T& x) {
        while (a != b) {
            if (*a == x) return a;
            ++a;
        }
        return b;
    }

    template<typename T>
    void print_number_vector(const Vector<T>& a) {
        if constexpr (!std::is_arithmetic<T>::value) throw std::invalid_argument("Invalid type: Type must be numeric");
        std::string prompt = "[";
        for (int i=0; i < a.size(); ++i) {
            if (i == a.size() - 1) {
                prompt += std::to_string(a[i]);
                continue;
            }
            prompt += std::to_string(a[i]) + ", ";
        }
        prompt += "]";
        std::cout << prompt << std::endl;
    }
}