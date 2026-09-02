#include <CLI/CLI.hpp>
#include <filesystem>
#include <octo/cpu/cpu.hpp>
#include <octo_log.h>
#include <print>

int main(int argc, char **argv) {

	log_set_level(LogLevel::Error);

	log_info("[Main]", "Starting Octo");
	CLI::App app{"Octo virtual CPU"};

	auto *run = app.add_subcommand("run", "Run an Octo program");

	std::filesystem::path file;
	run->add_option("file", file, "Program file")->required();

	app.parse(argc, argv);

	if (*run) {
		CPU cpu{0b00000000, 0b00000001};

		cpu.start(file);
	}
}
