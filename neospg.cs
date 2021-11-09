using System;
using McMaster.Extensions.CommandLineUtils;
using NeoSimplestStrongPasswordGenerator.Configuration;

namespace NeoSimplestStrongPasswordGenerator
{
	public class NeoSPG
	{
		private static int ReturnInt;
		public static int Main(string[] args)
		{
			CommandLineApplication neospg = new CommandLineApplication();
			neospg.HelpOption("--help|-h|-?");
			neospg.VersionOption("--version|-V", Config.version);
			
			CommandOption optString = neospg.Option("--string -s <STRING>", "String used for characters being chosen", CommandOptionType.SingleValue);
			CommandOption optNumber = neospg.Option("--number -n <INT>", "The number of characters being generated", CommandOptionType.SingleValue);

			neospg.OnExecute(() =>
			{
				return Generate(optString, optNumber);
			} );
			neospg.Execute(args);
			return ReturnInt;
		}

		public static int Generate( CommandOption theString, CommandOption Number)
		{
			string @string=Config.DefaultString;
			int number=Config.DefaultNumber;	
			if(theString.HasValue())
			{
				@string=theString.Value();
			}
			if(Number.HasValue())
			{
				if(!int.TryParse(Number.Value(), out number))
				{
					Console.WriteLine("--number is not a number!");
					ReturnInt=1;
					return 0;
				}
			}
			// Generate
			char[] @char= @string.ToCharArray();
			Random theRandom = new Random();
			for (int i = 0; i < number; i++) { Console.Write(@char[theRandom.Next(@char.Length)]);}
			Console.Write('\n');
			ReturnInt=0;
			return 0;
		}
	}
}

