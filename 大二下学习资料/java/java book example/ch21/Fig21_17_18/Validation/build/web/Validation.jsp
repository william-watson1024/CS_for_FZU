<?xml version="1.0" encoding="UTF-8"?>

<!-- Fig. 22.17 Validation.jsp -->
<!-- JSP that demonstrates validation of user input. -->
<jsp:root version="2.1" xmlns:f="http://java.sun.com/jsf/core" 
   xmlns:h="http://java.sun.com/jsf/html" 
   xmlns:jsp="http://java.sun.com/JSP/Page" 
   xmlns:webuijsf="http://www.sun.com/webui/webuijsf">
   <jsp:directive.page contentType="text/html;charset=UTF-8" 
      pageEncoding="UTF-8"/>
   <f:view>
      <webuijsf:page id="page1">
         <webuijsf:html id="html1">
            <webuijsf:head id="head1">
               <webuijsf:link id="link1" url="/resources/stylesheet.css"/>
            </webuijsf:head>
            <webuijsf:body id="body1" style="-rave-layout: grid">
               <webuijsf:form id="form1">
                  <webuijsf:staticText id="headerText" 
                     style="font-size: 18px; left: 24px; top: 24px;
                        position: absolute" 
                     text="Please fill out the following form:"/>
                  <webuijsf:staticText id="instructionText" 
                     style="font-style: italic; left: 24px; top: 48px;
                        position: absolute" 
                     text="All fields are required and must contain
                        valid information."/>
                  <webuijsf:label for="nameTextField" id="nameLabel" 
                     style="left: 24px; top: 72px; position: absolute" 
                     text="Name:"/>
                  <webuijsf:textField binding="#{Page1.nameTextField}" 
                     columns="30" id="nameTextField" required="true"
                     style="position: absolute; left: 96px; top: 72px" 
                     validatorExpression=
                        "#{Page1.nameLengthValidator.validate}"/>
                  <webuijsf:message for="nameTextField" id="nameMessage" 
                     showDetail="false" showSummary="true" 
                     style="left: 312px; top: 72px; position: absolute"/>
                  <webuijsf:label for="emailTextField" id="emailLabel" 
                     style="left: 24px; top: 96px; position: absolute" 
                     text="E-Mail:"/>
                  <webuijsf:textField binding="#{Page1.emailTextField}" 
                     columns="30" id="emailTextField" required="true"
                     style="left: 96px; top: 96px; position: absolute" 
                     validatorExpression=
                        "#{Page1.emailTextField_validate}"/>
                  <webuijsf:message for="emailTextField" 
                     id="emailMessage" showDetail="false" 
                     showSummary="true" 
                     style="left: 312px; top: 96px; position: absolute"/>
                  <webuijsf:label for="phoneTextField" id="phoneLabel" 
                     style="left: 24px; top: 120px; position: absolute" 
                     text="Phone:"/>
                  <webuijsf:textField binding="#{Page1.phoneTextField}" 
                     columns="30" id="phoneTextField" required="true"
                     style="left: 96px; top: 120px; position: absolute" 
                     validatorExpression=
                        "#{Page1.phoneTextField_validate}"/>
                  <webuijsf:message for="phoneTextField" 
                     id="phoneMessage" showDetail="false" 
                     showSummary="true" style="left: 312px; top: 120px;
                        position: absolute"/>
                  <webuijsf:button actionExpression=
                     "#{Page1.submitButton_action}" id="submitButton" 
                     style="position: absolute; left: 24px; top: 144px" 
                     text="Submit"/>
                  <webuijsf:staticText binding="#{Page1.resultText}" 
                     escape="false" id="resultText" rendered="false"
                     style="left: 24px; top: 168px; position: absolute" 
                     text="Thank you for your submission.&lt;br/&gt;We 
                        received the following information:"/>
                  <h:panelGrid binding="#{Page1.gridPanel}" 
                     columns="2" id="gridPanel" rendered="false"
                     style="border-width: 1px; border-style: solid;
                        background-color: #ffff99; height: 96px; 
                        left: 24px; top: 216px; position: absolute" 
                     width="264">
                     <webuijsf:staticText id="nameText" text="Name:"/>
                     <webuijsf:staticText 
                        binding="#{Page1.nameValueText}" 
                        id="nameValueText"/>
                     <webuijsf:staticText id="emailText" 
                        text="E-Mail:"/>
                     <webuijsf:staticText 
                        binding="#{Page1.emailValueText}" 
                        id="emailValueText"/>
                     <webuijsf:staticText id="phoneText" text="Phone:"/>
                     <webuijsf:staticText 
                        binding="#{Page1.phoneValueText}" 
                        id="phoneValueText"/>
                  </h:panelGrid>
               </webuijsf:form>
            </webuijsf:body>
         </webuijsf:html>
      </webuijsf:page>
   </f:view>
</jsp:root>
<!-- 
********************************************************************** 
* (C) Copyright 1992-2009 by Deitel & Associates, Inc. and           *
* Pearson Education, Inc. All Rights Reserved.                       *
*                                                                    *
* DISCLAIMER: The authors and publisher of this book have used their *
* best efforts in preparing the book. These efforts include the      *
* development, research, and testing of the theories and programs    *
* to determine their effectiveness. The authors and publisher make   *
* no warranty of any kind, expressed or implied, with regard to      *
* these programs or to the documentation contained in these books.   *
* The authors and publisher shall not be liable in any event for     *
* incidental or consequential damages in connection with, or         *
* arising out of, the furnishing, performance, or use of these       *
* programs.                                                          *
********************************************************************** 
-->
