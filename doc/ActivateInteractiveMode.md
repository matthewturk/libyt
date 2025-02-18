# Activate Interactive Mode

## yt\_run\_InteractiveMode
```cpp
int yt_run_InteractiveMode(const char* flag_file_name);
```
> :information_source: Should include `libyt_interactive_mode.h` header.
- Usage: It will first run other inline python functions that are set to [run](./InteractivePythonPrompt.md#run-1) but haven't called by [`yt_run_Function`](./PerformInlineAnalysis.md#yt_run_function) or [`yt_run_FunctionArguments`](./PerformInlineAnalysis.md#yt_run_functionarguments) yet. Then it activates [interactive python prompt](./InteractivePythonPrompt.md#interactive-python-prompt) when there are errors occurred or file `flag_file_name` is detected.
- Return: `YT_SUCCESS` or `YT_FAIL`

## Example
```cpp
#include "libyt_interactive_mode.h"
...
if (yt_run_InteractiveMode("LIBYT_STOP") != YT_SUCCESS) {
    fprintf(stderr, "ERROR: yt_run_InteractiveMode failed!\n");
    exit(EXIT_FAILURE);
}
```