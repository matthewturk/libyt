#ifndef __LIBYT_FUNC_STATUS_LIST_H__
#define __LIBYT_FUNC_STATUS_LIST_H__

#include <vector>
#include <string>
#include "func_status.h"

class func_status_list {
private:
    std::vector<func_status> m_FuncStatusList;

public:
    func_status_list(int capacity) { m_FuncStatusList.reserve(capacity); };
    ~func_status_list() { m_FuncStatusList.clear(); };
    func_status& operator[](int index) { return m_FuncStatusList[index]; };

    int reset();
    int size() { return (int) m_FuncStatusList.size(); };
    int print_summary();
    int get_func_index(const char *func_name);
    int add_new_func(char *func_name, int run);

    static int load_func_body(const char *filename);
    static std::vector<std::string> get_funcname_defined(const char *filename);
};


#endif // #ifndef __LIBYT_FUNC_STATUS_LIST_H__
