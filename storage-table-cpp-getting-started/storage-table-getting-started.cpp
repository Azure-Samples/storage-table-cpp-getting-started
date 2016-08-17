//----------------------------------------------------------------------------------
// Microsoft Developer & Platform Evangelism
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//
// THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, 
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES 
// OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
//----------------------------------------------------------------------------------
// The example companies, organizations, products, domain names,
// e-mail addresses, logos, people, places, and events depicted
// herein are fictitious.  No association with any real company,
// organization, product, domain name, email address, logo, person,
// places, or events is intended or should be inferred.
//----------------------------------------------------------------------------------

#include "stdafx.h"
#include "table_basic.h"
#include "table_advanced.h"

using namespace azure::storage;

void run_storage_table_samples(utility::string_t storage_connection_string);

int main()
{
  // *************************************************************************************************************************
  // Instructions: This sample can be run using either the Azure Storage Emulator that installs as part of the Windows Azure SDK (in Windows only) - or by
  // updating the storage_connection_string with your AccountName and Key. 
  // 
  // To run the sample using the Storage Emulator (Windows Azure SDK)
  //      1. Start the Azure Storage Emulator (once only) by pressing the Start button or the Windows key and searching for it
  //         by typing "Azure Storage Emulator". Select it from the list of applications to start it.
  //      2. Set breakpoints and run the project using F10. 
  // 
  // To run the sample using the Storage Service
  //      1. Update the storage_connection_string variable for the emulator (UseDevelopmentStorage=True) and
  //         replace it with the storage_connection_string for the storage service (AccountName=[]...)
  //      2. Create a Storage Account through the Azure Portal and provide your [AccountName] and [AccountKey] in 
  //         the App.Config file. See http://go.microsoft.com/fwlink/?LinkId=325277 for more information
  //      3. Set breakpoints and run the project using F10. 
  // 
  // *************************************************************************************************************************

  const utility::string_t storage_connection_string(U("UseDevelopmentStorage=true"));

  try
  {
    run_storage_table_samples(storage_connection_string);
  }
  catch (const azure::storage::storage_exception& e)
  {
    ucout << U("Error:") << e.what() << std::endl << U("Unexpected exception while running the sample.") << std::endl;
  }

  return 0;
}

/// 
/// Demonstrates how to perform common tasks using the Microsoft Azure Table storage including creating a table, 
/// CRUD operations, batch operations and different querying techniques.
///
void run_storage_table_samples(utility::string_t storage_connection_string)
{
  // Parse the connection string
  cloud_storage_account storage_account = cloud_storage_account::parse(storage_connection_string);

  cloud_table_client table_client = storage_account.create_cloud_table_client();

  // basic operations with tables
  table_basic::table_operations(table_client);

  // list tables in account
  table_advanced::list_tables(table_client);

  // set service properties
  table_advanced::set_service_properties(table_client);

  // set container permissions
  table_advanced::set_table_acl(table_client);
}

