# Flag_Inserter
Sistema embarcado em um STM32 para retransmissão de dados Seriais que recebe dados em uma porta serial e os encaminha para outra porta serial.  Adicionalmente o sistema insere uma mensagem do tipo flag de vida em intervalos regulares de tempo para verificação da integridade da linha de transmissão serial. Por meio do uso de flags diferenciadas, permite identificar a origem do fluxo em casos de destino com sinal Serial roteado de multiplas origens.

Atualização: Sistema acabou sendo desenvolvido na plataforma arduíno pela simplicidade.
Arquivos estão dentro da pasta Arduíno inserter.