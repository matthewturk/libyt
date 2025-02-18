# Initialize
## yt\_initialize
```cpp
int yt_initialize(int argc, char *argv[], const yt_param_libyt *param_libyt)
```
- Usage: Initialize `libyt` and import your Python script. This API should only be called once.
- Return: `YT_SUCCESS` or `YT_FAIL`.

## yt_param_libyt
- `yt_verbose verbose` (Default=`YT_VERBOSE_WARNING`)
  - Usage: Set the log message level.
  - Valid Value for `yt_verbose`:
    - `YT_VERBOSE_OFF`: Turn off log message.
    - `YT_VERBOSE_INFO`: Output log level below or equal to info.
    - `YT_VERBOSE_WARNING`: Output log level below or equal to warning.
    - `YT_VERBOSE_DEBUG`: Output all log.
- `const char* script` (Default=`yt_inline_script`)
  - Usage: Your Python script name. Do NOT contain `.py`. Make it a unique name that is different from python module name.
  > :pencil2: Please make sure the lifetime of `script` covers the whole in situ analysis process.
- `long counter` (Default=`0`)
  - Usage: Number of rounds doing inline-analysis, may be useful in restart. We also append this number at the end of the figure name.
- `bool check_data` (Default=`true`)
  - Usage: Check the input data (ex: hierarchy, grid information…), if it is true. You should set this to `false` after you have successfully implemented libyt.



## Example
```cpp
int main(int argc, char *argv[]){
    ...
    yt_param_libyt param_libyt;
    param_libyt.verbose = YT_VERBOSE_DEBUG;
    param_libyt.script  = "inline_script";
    param_libyt.check_data = false;
	
    /* Initialize libyt, should only be called once. */
    if( yt_initialize( argc, argv, &param_libyt ) != YT_SUCCESS ){
        // error message
        exit( EXIT_FAILURE );
    }
    ...
}
```
