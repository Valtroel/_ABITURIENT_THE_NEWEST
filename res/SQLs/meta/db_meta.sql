EXECUTE
    ibeblock
AS
BEGIN
    cbb =
        'EXECUTE
            ibeblock
            (
                LogLine
                variant
            )
        AS
        BEGIN
            ibec_progress(LogLine);
        END';

    DB =
        ibec_CreateConnection
        (
            __ctInterBase, 
            'DBName="172.16.1.30:abiturient";
            ClientLib=D:\DbFireBird\fbclient.dll;
            User=SYSDBA;
            Password=dbudfV544703;
            Names=WIN1251;
            SqlDialect=1'
        );

    TRY
        ibec_ExtractMetadata
        (
            DB,
            '',
            'GenerateCreate;
            IncludePassword;
            SetGenerators;
            ExtractDescriptions;
            UseComment;
            DateFormat=YYYY-MM-DD;
            DateTimeFormat=YYYY-MM-DD HH:NN:SS;
            Domains=NONE;
            Tables=NONE;
            Views=NONE;
            Procedures=NONE;
            Functions=NONE;
            Packages=NONE;
            Triggers=NONE;
            Generators=NONE;
            Exceptions=NONE;
            UDFs=NONE;
            Roles=NONE;
            DataTables=NONE', 
            cbb
        );
    FINALLY
        ibec_CloseConnection(DB);
    END;
END;