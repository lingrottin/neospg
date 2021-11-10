# NeoSPG
A new Simplest Strong Password Generator.  

## How to use it?
First, go to [releases page](https://github.com/lingrottin/neospg/releases), download one which fits your OS.  
*( NOTE: If I haven't complied binary file for your platform, please refer to [build guide](/README.md#Build_it_yourself) )*  
*( NOTE: You may need to get .NET Core or Mono runtime installed in order to run it )*  
*( NOTE: mono build is cross-platform but you need Mono runtime to run it )*  
Open your console, try these commands:
```bash
./neospg # if you got dotnet core build
mono ./neospg.exe # if you got mono build
```
```powershell
.\neospg.exe # both usable for dotnet core and mono
```

## Wow, 3600 is too much!
NeoSPG uses powerful [CommandLineUtils](https://github.com/natemcmaster/CommandLineUtils) class lib. And this provides NeoSPG the ability to parse command line arguments.  
Simple use these when you are executing `neospg`:
```powershell
neospg -n18 -s abcdefg
neospg -n:18 -s="NeoSPG is fucking best!"
neospg --help # if you're wanting to get the usage of arguments
```

## I want to modify the default configuration! How to?
NeoSPG doesn't support the usage of environment variables *(but I think it will ;P)*  
So as for now, the only way to modify the default settings is to modify the source code.
### Meet `config.cs` !
To make users able to modify the configuration, I used a dwm-form configuration - `config.cs`.  
Simply open it, and you will know everything:
```csharp
/* Sample code, modified */
public static string version="A sample configuration"; // Version, printed in "--help" and "--version"
public static int DefaultNumber=8848; // the number of characters generated when there's no "-n" option
public static string DefaultString="I_Am-a~String!"; // the characters to be chosen from
```
And then [build it yourself](/README.md#Build_it_yourself)


## Build it yourself
NeoSPG can be built in several environments. But make sure you have any of these installed to reach the simplest compiling progress.  
* .NET 5.0.11 SDK 
* Mono 6 SDK
* .NET Framework 4.5 SDK
And make sure you have MSBuild version 16 in these SDKs.  
### Prepare the build environment
#### `DOTNET_ROOT` variable
If your .NET Core is not in `/usr/share/dotnet`, set `$DOTNET_ROOT` environment to dotnet core installed directory first. As for me, it's in `/opt/dotnet`:
```bash
export DOTNET_ROOT=/opt/dotnet
```
#### Check MSBuild
Check if MSBuild is in your system:
```powershell
MSBuild -version
```
#### Get the source code
* Go to [releases](https://github.com/lingrottin/neospg/releases) and download the newest source code.
* Or clone it using `git`
```bash
git clone https://github.com/lingrottin/neospg.git
```
#### Prepare for Mono/Framework
Skip this if you're using .NET Core.
```bash
cp -r neospg/ neospg-mono/ #We'd better make a new directory to compile it
cat neospg-mono/neospg-mono.csproj > neospg-mono/neospg.csproj # if don't do this, binary file will be named as "neospg-mono"
```

### Start the build!
If you're using .NET Core:
```powershell
dotnet build -c Release
dotnet publish -p:Configuration=Release NeoSPG/NeoSPG.csproj # if you want fewer files
```
If you're using .NET Framework or Mono:
```powershell
Msbuild -p:Configuration=Release -t:Publish -restore:True neospg-mono/neospg.csproj
```
When build completes, you can find your binaries in <code>NeoSPG's source dir/bin/Release/net<i>XX</i>/publish</code>  
(If you compiled it with .NET 5, `netXX` will be `net5.0`, else it will be `net45` )

## Special thanks
* [@ltfjx](https://GitHub.com/ltfjx), as NeoSPG is a rewrite to his [SPG](https://GitHub.com/ltfjx/spg)
* [McMaster](https://github.com/natemcmaster), maintains Microsoft's ruined CommandLineUtils' [fork](https://github.com/natemcmaster/CommandLineUtils)
