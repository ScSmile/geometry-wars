Package: bzip2[core,tool]:x64-windows@1.0.8#5

**Host Environment**

- Host: x64-windows
- Compiler: MSVC 19.41.34123.0
-    vcpkg-tool version: 2024-06-10-02590c430e4ed9215d27870138c2e579cc338772
    vcpkg-readonly: true
    vcpkg-scripts version: 6f1ddd6b6878e7e66fcc35c65ba1d8feec2e01f8

**To Reproduce**

`vcpkg install `

**Failure logs**

```
-- Downloading https://sourceware.org/pub/bzip2/bzip2-1.0.8.tar.gz -> bzip2-1.0.8.tar.gz...
[DEBUG] To include the environment variables in debug output, pass --debug-env
[DEBUG] Trying to load bundleconfig from C:\Program Files\Microsoft Visual Studio\2022\Community\VC\vcpkg\vcpkg-bundle.json
[DEBUG] Bundle config: readonly=true, usegitregistry=true, embeddedsha=6f1ddd6b6878e7e66fcc35c65ba1d8feec2e01f8, deployment=VisualStudio, vsversion=17.0
[DEBUG] VS telemetry opted in at SOFTWARE\WOW6432Node\Microsoft\VSCommon\17.0\SQM\\OptIn
[DEBUG] Metrics enabled.
[DEBUG] Feature flag 'binarycaching' unset
[DEBUG] Feature flag 'compilertracking' unset
[DEBUG] Feature flag 'registries' unset
[DEBUG] Feature flag 'versions' unset
[DEBUG] Feature flag 'dependencygraph' unset
Downloading https://sourceware.org/pub/bzip2/bzip2-1.0.8.tar.gz
warning: Download failed -- retrying after 1000ms
warning: Download failed -- retrying after 2000ms
warning: Download failed -- retrying after 4000ms
error: Failed to download from mirror set
error: https://sourceware.org/pub/bzip2/bzip2-1.0.8.tar.gz: WinHttpSendRequest failed with exit code 12007
error: https://sourceware.org/pub/bzip2/bzip2-1.0.8.tar.gz: WinHttpSendRequest failed with exit code 12007
error: https://sourceware.org/pub/bzip2/bzip2-1.0.8.tar.gz: WinHttpSendRequest failed with exit code 12007
error: https://sourceware.org/pub/bzip2/bzip2-1.0.8.tar.gz: WinHttpSendRequest failed with exit code 12007
[DEBUG] D:\a\_work\1\s\src\vcpkg\base\downloads.cpp(997): 
[DEBUG] Time in subprocesses: 0us
[DEBUG] Time in parsing JSON: 9us
[DEBUG] Time in JSON reader: 0us
[DEBUG] Time in filesystem: 1024us
[DEBUG] Time in loading ports: 0us
[DEBUG] Exiting after 8.1 s (8040752us)

CMake Error at scripts/cmake/vcpkg_download_distfile.cmake:32 (message):
      
      Failed to download file with error: 1
      If you are using a proxy, please check your proxy setting. Possible causes are:
      
      1. You are actually using an HTTP proxy, but setting HTTPS_PROXY variable
         to `https://address:port`. This is not correct, because `https://` prefix
         claims the proxy is an HTTPS proxy, while your proxy (v2ray, shadowsocksr
         , etc..) is an HTTP proxy. Try setting `http://address:port` to both
         HTTP_PROXY and HTTPS_PROXY instead.
      
      2. If you are using Windows, vcpkg will automatically use your Windows IE Proxy Settings
         set by your proxy software. See https://github.com/microsoft/vcpkg-tool/pull/77
         The value set by your proxy might be wrong, or have same `https://` prefix issue.
      
      3. Your proxy's remote server is out of service.
      
      If you've tried directly download the link, and believe this is not a temporary
      download server failure, please submit an issue at https://github.com/Microsoft/vcpkg/issues
      to report this upstream download server failure.
      

Call Stack (most recent call first):
  scripts/cmake/vcpkg_download_distfile.cmake:270 (z_vcpkg_download_distfile_show_proxy_and_fail)
  C:/Users/ScSmile/AppData/Local/vcpkg/registries/git-trees/92e9a8bbf1abbd89872b48ad82fcf75852de1006/portfile.cmake:1 (vcpkg_download_distfile)
  scripts/ports.cmake:175 (include)



```

**Additional context**

<details><summary>vcpkg.json</summary>

```
{
  "dependencies": [
    "imgui",
    "sfml"
  ]
}

```
</details>
