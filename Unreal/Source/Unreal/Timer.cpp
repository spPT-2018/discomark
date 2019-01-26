#include "Timer.h"

// Sets default values for this component's properties
UTimer::UTimer()
{
	PrimaryComponentTick.bCanEverTick = true;

}

FString SaveDirectory = FString("C:/Users/tobia/Documents/discomark/");
FString FileName = FString("Unreal C++ (editor).csv");
bool AllowOverwriting = true;

IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

std::string test_results = "";

void write_to_log_file() {
	// CreateDirectoryTree returns true if the destination
	// directory existed prior to call or has been created
	// during the call.
	if (PlatformFile.CreateDirectoryTree(*SaveDirectory)) {
		// Get absolute file path
		FString AbsoluteFilePath = SaveDirectory + "/" + FileName;

		// Allow overwriting or file doesn't already exist
		if (AllowOverwriting || !PlatformFile.FileExists(*AbsoluteFilePath)) {
			FFileHelper::SaveStringToFile(FString(test_results.c_str()), *AbsoluteFilePath);
		}
	}
}

void open_file() {
	test_results += "Iterations,Runtime(nanos)\n";
}

void printResults(int iteration, long long runtime) {
	test_results += std::to_string(iteration) + "," + std::to_string(runtime) + "\n";
}

long long nanoTime() {
	std::chrono::time_point<std::chrono::system_clock> now =
		std::chrono::system_clock::now();

	return std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch()).count();
}


// Called when the game starts
void UTimer::BeginPlay()
{
	Super::BeginPlay();
	open_file();
	iterations = 0;
	lastTimestamp = nanoTime();
	// ...
	
}


// Called every frame
void UTimer::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	auto time = nanoTime() - lastTimestamp;
	printResults(iterations, time);
	iterations++;
	lastTimestamp = nanoTime();
}

void UTimer::BeginDestroy() {
	write_to_log_file();
	Super::BeginDestroy();
}
