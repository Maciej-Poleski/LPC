
set(INPUT_SOURCE_FILES ExampleDialog.cxx MainWidget.cxx DatabaseException.cxx ExamplesTableModel.cxx SqlDatabaseFactory.cxx MainWindow.cxx)
set(INPUT_HEADER_FILES ExampleDialog.hxx MainWidget.hxx DatabaseException.hxx ExamplesTableModel.hxx SqlDatabaseFactory.hxx MainWindow.hxx)
set(OUTPUT_SOURCE_FILES ${INPUT_SOURCE_FILES})
set(OUTPUT_HEADER_FILES ${INPUT_HEADER_FILES})

qt4_wrap_cpp(OUTPUT_SOURCE_FILES ${INPUT_HEADER_FILES})

add_library(LPCCore SHARED ${OUTPUT_SOURCE_FILES})