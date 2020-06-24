<!-- Model 1, Model 2 -->
<!--<%@page import="com.springbook.biz.board.impl.BoardDAO"%>-->
<!--<%@page import="com.springbook.biz.board.BoardVO"%>-->
<%@page contentType="text/html; charset=EUC-KR"%>

<!-- Model 1, Model 2 -->
<!-- <%
	// Model 1
	// 1. �˻��� �Խñ� ��ȣ ����
	//String seq = request.getParameter("seq");

	// 2. DB ���� ó��
	/*
	BoardVO vo = new BoardVO();
	vo.setSeq(Integer.parseInt(seq));
	
	BoardDAO boardDAO = new BoardDAO();
	BoardVO board = boardDAO.getBoard(vo);
	*/
	// 3. ���� ȭ�� ����
	
	// Model 2
	// ���ǿ� ����� �Խñ� ������ ������.
	BoardVO board = (BoardVO) session.getAttribute("board");
%> -->

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=EUC-KR">
<title>�� ��</title>
</head>
<body>
<center>
<h1>�� ��</h1>
<!-- Model 1 -->
<!-- <a href="logout_proc.jsp">Log-out</a> -->
<!-- Model 2 -->
<a href="logout.do">Log-out</a>
<hr>
<!-- Model 1 -->
<!-- <form action="updateBoard_proc.jsp" method="post"> -->
<!-- Model 2 -->
<form action="updateBoard.do" method="post">
<!-- Model 1, Model 2 -->
<!-- <input name="seq" type="hidden" value="<%= board.getSeq() %>" /> -->
<!-- Servlet -->
<input name="seq" type="hidden" value="${board.seq }" />
<table border="1" cellpadding="0" cellspacing="0">
	<tr>
		<td bgcolor="orange" width="70">����</td>
		<!-- Model 1, Model 2 -->
		<!-- <td align="left"><input name="title" type="text" value="<%= board.getTitle() %>" /></td> -->
		<!-- Servlet -->
		<td align="left"><input name="title" type="text" value="${board.title }" /></td>
	</tr>
	<tr>
		<td bgcolor="orange">�ۼ���</td>
		<!-- Model 1, Model 2 -->
		<!-- <td align="left"><%= board.getWriter() %></td> -->
		<!-- Servlet -->
		<td align="left">${board.writer }</td>
	</tr>
	<tr>
		<td bgcolor="orange">����</td>
		<!-- Model 1, Model 2 -->
		<!-- <td align="left"><textarea name="content" rows="10" cols="40"><%= board.getContent() %></textarea></td> -->
		<!-- Servlet -->
		<td align="left"><textarea name="content" rows="10" cols="40">${board.content }</textarea></td>
	</tr>
	<tr>
		<td bgcolor="orange">�����</td>
		<!-- Model 1, Model 2 -->
		<!-- <td align="left"><%= board.getRegDate() %></td> -->
		<!-- Servlet -->
		<td align="left">${board.regDate }</td>
	</tr>
	<tr>
		<td bgcolor="orange">��ȸ��</td>
		<!-- Model 1, Model 2 -->
		<!-- <td align="left"><%= board.getCnt() %></td> -->
		<!-- Servlet -->
		<td align="left">${board.getCnt }</td>
	</tr>
	<tr>
		<td colspan="2" align="center">
			<input type="submit" value="�� ����" />
		</td>
	</tr>
</table>
</form>
<hr>
<a href="insertBoard.jsp">�� ���</a>&nbsp;&nbsp;&nbsp; <!-- &nbsp�� ������ �����. -->
<!-- Model 1 -->
<!-- <a href="deleteBoard_proc.jsp?seq=<%= board.getSeq() %>">�� ����</a>&nbsp;&nbsp;&nbsp;
<a href="getBoardList.jsp">�� ���</a> -->
<!-- Model 2 -->
<!-- <a href="deleteBoard.do?seq=<%= board.getSeq() %>">�� ����</a>&nbsp;&nbsp;&nbsp; -->
<!-- Servlet -->
<a href="deleteBoard.do?seq=${board.seq }">�� ����</a>&nbsp;&nbsp;&nbsp;
<a href="getBoardList.do">�� ���</a>
</center>
</body>
</html>